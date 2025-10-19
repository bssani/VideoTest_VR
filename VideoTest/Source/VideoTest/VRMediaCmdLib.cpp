#include "VRMediaCmdLib.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"

bool UVRMediaCmdLib::GetCmdOptions(FString& OutVideo, bool& bOutIs180, FString& OutStereo)
{
    const TCHAR* Cmd = FCommandLine::Get();
    FParse::Value(Cmd, TEXT("Video="), OutVideo);   // -Video="C:/videos/a.mp4" or ../../../Project/Content/Movies/a.mp4
    bOutIs180 = FParse::Param(Cmd, TEXT("Is180"));  // -Is180 ¿÷¿∏∏È true
    FParse::Value(Cmd, TEXT("Stereo="), OutStereo); // -Stereo=Mono/SBS/OU
    return !OutVideo.IsEmpty();
}
