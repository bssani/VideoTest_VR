#include "VRMediaSphere.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Engine/Engine.h"

AVRMediaSphere::AVRMediaSphere(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // Default subobjects
    SphereMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("SphereMesh"));
    RootComponent = SphereMesh;

    MediaSound = ObjectInitializer.CreateDefaultSubobject<UMediaSoundComponent>(this, TEXT("MediaSound"));
    MediaSound->SetupAttachment(RootComponent);
    MediaSound->SetAutoActivate(true);

    // 기본 스피어
    static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultSphere(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
    if (DefaultSphere.Succeeded())
    {
        FullSphereMesh = DefaultSphere.Object;
        SphereMesh->SetStaticMesh(FullSphereMesh);
        SphereMesh->SetWorldScale3D(FVector(-200.f, 200.f, 200.f)); // 내부 보기
        SphereMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }

    // 머티리얼 (M_VideoEquirect, 파라미터명 "VideoTex")
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatRef(TEXT("/Game/VRMedia/Materials/M_VideoEquirect.M_VideoEquirect"));
    if (MatRef.Succeeded())
    {
        BaseEquirectMaterial = MatRef.Object;
    }
}

void AVRMediaSphere::CreateMediaObjects()
{
    MediaPlayer = NewObject<UMediaPlayer>(this, UMediaPlayer::StaticClass(), NAME_None, RF_Transient);
    MediaTex = NewObject<UMediaTexture>(this, UMediaTexture::StaticClass(), NAME_None, RF_Transient);
    FileSource = NewObject<UFileMediaSource>(this, UFileMediaSource::StaticClass(), NAME_None);

    if (MediaTex && MediaPlayer)
    {
        MediaTex->SetMediaPlayer(MediaPlayer);
        MediaTex->UpdateResource();
    }
    if (MediaSound && MediaPlayer)
    {
        MediaSound->SetMediaPlayer(MediaPlayer);
    }
}

void AVRMediaSphere::BeginPlay()
{
    Super::BeginPlay();

    CreateMediaObjects();
    InitMedia();
    OpenMedia(VideoPath);
    bRequestedPlay = true;
}

void AVRMediaSphere::InitMedia()
{
    if (BaseEquirectMaterial)
    {
        MID = UMaterialInstanceDynamic::Create(BaseEquirectMaterial, this);
        if (MID && MediaTex)
        {
            MID->SetTextureParameterValue(TEXT("VideoTex"), MediaTex);
            SphereMesh->SetMaterial(0, MID);
        }
    }

    if (bIs180 && HalfSphereMesh)
        SphereMesh->SetStaticMesh(HalfSphereMesh);
    else if (FullSphereMesh)
        SphereMesh->SetStaticMesh(FullSphereMesh);
}

bool AVRMediaSphere::OpenMedia(const FString& FilePath)
{
    if (!MediaPlayer || !FileSource) return false;

    FileSource->FilePath = FilePath;
    MediaPlayer->SetLooping(true);

    const bool bOpened = MediaPlayer->OpenSource(FileSource);
    if (!bOpened)
    {
        UE_LOG(LogTemp, Error, TEXT("Media Open failed: %s"), *FilePath);
        return false;
    }
    return true;
}

void AVRMediaSphere::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    // UE5: CanPlay() 없음 → IsReady()/IsPreparing() 사용
    if (bRequestedPlay && MediaPlayer && !MediaPlayer->IsPreparing() && MediaPlayer->IsReady())
    {
        MediaPlayer->Play();
        bRequestedPlay = false;
    }
}

void AVRMediaSphere::TogglePlayPause()
{
    if (!MediaPlayer) return;
    if (MediaPlayer->IsPlaying()) MediaPlayer->Pause();
    else MediaPlayer->Play();
}

void AVRMediaSphere::ToggleHemisphere()
{
    bIs180 = !bIs180;
    if (bIs180 && HalfSphereMesh)
        SphereMesh->SetStaticMesh(HalfSphereMesh);
    else if (FullSphereMesh)
        SphereMesh->SetStaticMesh(FullSphereMesh);
}

void AVRMediaSphere::SeekSeconds(int32 Seconds)
{
    if (!MediaPlayer) return;
    const FTimespan Now = MediaPlayer->GetTime();
    MediaPlayer->Seek(Now + FTimespan::FromSeconds(Seconds));
}
