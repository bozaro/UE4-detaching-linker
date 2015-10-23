# UE 4.9 Bug

UE4 Answerhub: https://answers.unrealengine.com/questions/321533/49-410-master-save-object-error-detaching-from-exi.html

## Steps to reproduce problem (original found)

 * Download project from
 * Open project with Unreal Engine 4.9+ (I tested on 4.9 and master https://github.com/EpicGames/UnrealEngine/commit/a2f8af8fb46a04587c95069a43342a6214cf093e)
 * Open SameCharacter blueprint
 * Save SameCharacter blueprint (press "Save this asset")
 * Press game in Editor (press "Play" button or Alt+P key)
 * Stop (press Esc key)
 * Save SameCharacter blueprint again (press "Save this asset")

**Expected result**: blueprint saved.

**Actual result**: Crash.

## Steps to reproduce problem (more simple)

 * Download project from
 * Open project with Unreal Engine 4.9
 * Open SameCharacter blueprint
 * Save SameCharacter blueprint (press "Save this asset")
 * Open SameGameMode blueprint
 * Open SameCharacter blueprint again
 * Save SameCharacter blueprint (press "Save this asset")
 
**Expected result**: blueprint saved.

**Actual result**: Crash.

## Log error
```
[2015.10.23-09.53.15:677][ 77]LogWorld: Game class is 'SomeGameMode_C'
[2015.10.23-09.53.15:682][ 77]LogWorld: Bringing World /Temp/UEDPIE_0_Untitled_1.Untitled_1 up for play (max tick rate 0) at 2015.10.23-12.53.15
[2015.10.23-09.53.15:683][ 77]LogActor:Warning: GameSession /Temp/UEDPIE_0_Untitled_1.Untitled_1:PersistentLevel.GameSession_0 has natively added scene component(s), but none of them were set as the actor's RootComponent - picking one arbitrarily
[2015.10.23-09.53.15:684][ 77]LogActor:Warning: GameNetworkManager /Temp/UEDPIE_0_Untitled_1.Untitled_1:PersistentLevel.GameNetworkManager_0 has natively added scene component(s), but none of them were set as the actor's RootComponent - picking one arbitrarily
[2015.10.23-09.53.15:684][ 77]LogWorld: Bringing up level for play took: 0.004036
[2015.10.23-09.53.15:689][ 77]PIE: Info Play in editor start time for /Temp/UEDPIE_0_Untitled_1 -0.008
The thread 0x11b8 has exited with code 0 (0x0).
The thread 0x3120 has exited with code 0 (0x0).
The thread 0x2164 has exited with code 0 (0x0).
[2015.10.23-09.53.16:701][100]LogParticles: Destroying 0 GPU particle simulations for FXSystem 0x000000037F83B920
[2015.10.23-09.53.17:493][119]Cmd: OBJ SAVEPACKAGE PACKAGE="/Game/SomeCharacter" FILE="E:/Work/W1/W1SaveFail/Content/SomeCharacter.uasset" SILENT=true
Assertion failed: !HasAnyFlags(RF_NeedLoad|RF_NeedPostLoad) [File:C:\Work\W1\UnrealEngine\Engine\Source\Runtime\CoreUObject\Private\UObject\UObjectLinker.cpp] [Line: 102] 
Detaching from existing linker for E:/Work/W1/W1SaveFail/Content/SomeCharacter.uasset while object W1PeriodicRegeneration /Game/SomeCharacter.Default__SomeCharacter_C:EnergyComponent.W1PeriodicRegeneration_1 needs loaded
UE4Editor-Win64-Debug.exe has triggered a breakpoint.
```

## Stacktrace
```
UE4Editor-CoreUObject-Win64-Debug.dll!UObject::SetLinker(FLinkerLoad * LinkerLoad, int LinkerIndex, bool bShouldDetachExisting) Line 102
UE4Editor-CoreUObject-Win64-Debug.dll!FLinkerLoad::DetachExport(int i) Line 4010
UE4Editor-CoreUObject-Win64-Debug.dll!FLinkerLoad::Detach() Line 4036
UE4Editor-CoreUObject-Win64-Debug.dll!FLinkerManager::ResetLoaders(UObject * InPkg) Line 112
UE4Editor-CoreUObject-Win64-Debug.dll!ResetLoaders(UObject * InPkg) Line 327
UE4Editor-CoreUObject-Win64-Debug.dll!ResetLoadersForSave(UObject * InOuter, const wchar_t * Filename) Line 613
UE4Editor-CoreUObject-Win64-Debug.dll!UPackage::SavePackage(UPackage * InOuter, UObject * Base, EObjectFlags TopLevelFlags, const wchar_t * Filename, FOutputDevice * Error, FLinkerLoad * Conform, bool bForceByteSwapping, bool bWarnOfLongFilename, unsigned int SaveFlags, const ITargetPlatform * TargetPlatform, const FDateTime & FinalTimeStamp, bool bSlowTask) Line 3156
UE4Editor-UnrealEd-Win64-Debug.dll!UEditorEngine::SavePackage(UPackage * InOuter, UObject * InBase, EObjectFlags TopLevelFlags, const wchar_t * Filename, FOutputDevice * Error, FLinkerLoad * Conform, bool bForceByteSwapping, bool bWarnOfLongFilename, unsigned int SaveFlags, const ITargetPlatform * TargetPlatform, const FDateTime & FinalTimeStamp, bool bSlowTask) Line 3778
UE4Editor-UnrealEd-Win64-Debug.dll!UEditorEngine::Exec_Obj(const wchar_t * Str, FOutputDevice & Ar) Line 4309
UE4Editor-UnrealEd-Win64-Debug.dll!UEditorEngine::Exec(UWorld * InWorld, const wchar_t * Stream, FOutputDevice & Ar) Line 5375
UE4Editor-UnrealEd-Win64-Debug.dll!UUnrealEdEngine::Exec(UWorld * InWorld, const wchar_t * Stream, FOutputDevice & Ar) Line 743
UE4Editor-UnrealEd-Win64-Debug.dll!InternalSavePackage(UPackage * PackageToSave, bool & bOutPackageLocallyWritable, FOutputDevice & SaveOutput) Line 2485
UE4Editor-UnrealEd-Win64-Debug.dll!FEditorFileUtils::PromptForCheckoutAndSave(const TArray<UPackage *,FDefaultAllocator> & InPackages, bool bCheckDirty, bool bPromptToSave, TArray<UPackage *,FDefaultAllocator> * OutFailedPackages, bool bAlreadyCheckedOut, bool bCanBeDeclined) Line 3009
UE4Editor-UnrealEd-Win64-Debug.dll!FAssetEditorToolkit::SaveAsset_Execute() Line 455
UE4Editor-Kismet-Win64-Debug.dll!FBlueprintEditor::SaveAsset_Execute() Line 7740
UE4Editor-UnrealEd-Win64-Debug.dll!TMemberFunctionCaller<FAssetEditorToolkit,void (__cdecl FAssetEditorToolkit::*)(void) __ptr64>::operator()<>() Line 162
UE4Editor-UnrealEd-Win64-Debug.dll!TBaseSPMethodDelegateInstance<0,FAssetEditorToolkit,0,TTypeWrapper<void> __cdecl(void)>::Execute() Line 282
UE4Editor-UnrealEd-Win64-Debug.dll!TBaseSPMethodDelegateInstance<0,FAssetEditorToolkit,0,void __cdecl(void)>::ExecuteIfSafe() Line 390
UE4Editor-Slate-Win64-Debug.dll!TBaseDelegate<void>::ExecuteIfBound() Line 482
UE4Editor-Slate-Win64-Debug.dll!FUICommandList::ExecuteAction(const TSharedRef<FUICommandInfo const ,0> InUICommandInfo) Line 88
UE4Editor-Slate-Win64-Debug.dll!SToolBarButtonBlock::OnClicked() Line 296
UE4Editor-Slate-Win64-Debug.dll!TMemberFunctionCaller<SToolBarButtonBlock,FReply (__cdecl SToolBarButtonBlock::*)(void) __ptr64>::operator()<>() Line 161
UE4Editor-Slate-Win64-Debug.dll!TTupleImpl<TIntegerSequence<> >::ApplyAfter_ExplicitReturnType<FReply,TMemberFunctionCaller<SToolBarButtonBlock,FReply (__cdecl SToolBarButtonBlock::*)(void) __ptr64> >(TMemberFunctionCaller<SToolBarButtonBlock,FReply (__cdecl SToolBarButtonBlock::*)(void)> && Func) Line 113
UE4Editor-Slate-Win64-Debug.dll!TBaseSPMethodDelegateInstance<0,SToolBarButtonBlock,0,FReply __cdecl(void)>::Execute() Line 282
UE4Editor-Slate-Win64-Debug.dll!TBaseDelegate<FReply>::Execute() Line 440
UE4Editor-Slate-Win64-Debug.dll!SButton::OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) Line 236
UE4Editor-Slate-Win64-Debug.dll!FSlateApplication::RoutePointerUpEvent::__l17::<lambda>(const FArrangedWidget & TargetWidget, const FPointerEvent & Event) Line 4273
UE4Editor-Slate-Win64-Debug.dll!FEventRouter::Route<FReply,FEventRouter::FToLeafmostPolicy,FPointerEvent,FReply <lambda>(const FArrangedWidget &, const FPointerEvent &) >(FSlateApplication * ThisApplication, FEventRouter::FToLeafmostPolicy RoutingPolicy, FPointerEvent EventCopy, const FSlateApplication::RoutePointerUpEvent::__l17::FReply <lambda>(const FArrangedWidget &, const FPointerEvent &) & Lambda) Line 214
UE4Editor-Slate-Win64-Debug.dll!FSlateApplication::RoutePointerUpEvent(FWidgetPath & WidgetsUnderPointer, FPointerEvent & PointerEvent) Line 4276
UE4Editor-Slate-Win64-Debug.dll!FSlateApplication::ProcessMouseButtonUpEvent(FPointerEvent & MouseEvent) Line 4660
UE4Editor-Slate-Win64-Debug.dll!FSlateApplication::OnMouseUp(const EMouseButtons::Type Button) Line 4638
UE4Editor-Core-Win64-Debug.dll!FWindowsApplication::ProcessDeferredMessage(const FDeferredWindowsMessage & DeferredMessage) Line 1403
UE4Editor-Core-Win64-Debug.dll!FWindowsApplication::DeferMessage(TSharedPtr<FWindowsWindow,0> & NativeWindow, HWND__ * InHWnd, unsigned int InMessage, unsigned __int64 InWParam, __int64 InLParam, int MouseX, int MouseY, unsigned int RawInputFlags) Line 1708
UE4Editor-Core-Win64-Debug.dll!FWindowsApplication::ProcessMessage(HWND__ * hwnd, unsigned int msg, unsigned __int64 wParam, __int64 lParam) Line 764
UE4Editor-Core-Win64-Debug.dll!FWindowsApplication::AppWndProc(HWND__ * hwnd, unsigned int msg, unsigned __int64 wParam, __int64 lParam) Line 627
user32.dll!00007ffe8f57250d()	Unknown
user32.dll!00007ffe8f572367()	Unknown
UE4Editor-Core-Win64-Debug.dll!WinPumpMessages() Line 862
UE4Editor-Core-Win64-Debug.dll!FWindowsPlatformMisc::PumpMessages(bool bFromMainLoop) Line 889
UE4Editor-Win64-Debug.exe!FEngineLoop::Tick() Line 2392
UE4Editor-Win64-Debug.exe!EngineTick() Line 52
UE4Editor-Win64-Debug.exe!GuardedMain(const wchar_t * CmdLine, HINSTANCE__ * hInInstance, HINSTANCE__ * hPrevInstance, int nCmdShow) Line 145
UE4Editor-Win64-Debug.exe!WinMain(HINSTANCE__ * hInInstance, HINSTANCE__ * hPrevInstance, char * __formal, int nCmdShow) Line 189
UE4Editor-Win64-Debug.exe!__tmainCRTStartup() Line 618
kernel32.dll!00007ffe8f2113d2()
ntdll.dll!00007ffe91ad5454()
```

## How to create broken assets manually step-by-step

### Asset: SomeCompoment.uasset

 * Create blueprint from parent class "ActorComponent" as ```SomeComponenet```
 * Save it

### Asset: SomeCharacter.uasset

 * Create blueprint from parent class "W1Character" as ```SomeCharacter```
 * Add component "Some Component"
 * Set "Energy (Inherited)" property "Resource > Regeneration" to ```W1Periodic Regeneration```
 * Save it

### Asset: SomeGameMode.uasset

 * Create blueprint from parent class "GameMode" as ```SomeGameMode```
 * Set "Classes > Default Pawn Class" to ```SomeCharacter```
 * Save it

### Project configuration

Set default Game Mode to ```SomeGameMode```