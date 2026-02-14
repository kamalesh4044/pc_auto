# OpenWorldMP (Unreal Engine 5.7 Starter)

This repository contains a starter C++ Unreal project for a **third-person open-world game** with:

- Story progression framework
- Replicated quest progression
- Multiplayer-ready core state
- Third-person character movement/camera scaffold
- Android-ready baseline settings for mobile builds

## Critical compile fix included (for UE 5.7)

If you got this error:
- "last build used an outdated BuildSettingsVersion"
- "OpenWorldMP could not be compiled"

This repo now includes the fix:
- `DefaultBuildSettings = BuildSettingsVersion.V6;`
- `IncludeOrderVersion = EngineIncludeOrderVersion.Latest;`

in both target files.

## Quick start on Windows (UE 5.7)

1. Install **Visual Studio 2022** with:
   - Desktop development with C++
   - Game development with C++
   - Windows 10/11 SDK
2. Right-click `OpenWorldMP.uproject` -> **Generate Visual Studio project files**.
3. Open `OpenWorldMP.sln` in Visual Studio.
4. Set config to:
   - `Development Editor`
   - `Win64`
5. Build solution (`Ctrl+Shift+B`).
6. Launch project by opening `OpenWorldMP.uproject`.

## If Unreal asks "Would you like to rebuild modules now?"

Choose **Yes**.

If it still fails, run from terminal in repo root:

```bash
"C:/Program Files/Epic Games/UE_5.7/Engine/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool.exe" OpenWorldMPEditor Win64 Development -Project="<ABSOLUTE_PATH>/OpenWorldMP.uproject" -WaitMutex -FromMsBuild
```

Then regenerate project files once and reopen.

## Android 15 setup (best-practice baseline)

Project now sets:
- `TargetSDKVersion=35` (Android 15)
- `bBuildForArm64=True`
- mobile renderer defaults with Lumen/Nanite disabled for performance

In Unreal Editor also configure:
1. **Edit -> Project Settings -> Platforms -> Android SDK**:
   - Set SDK/NDK/JDK paths (or use AutoSDK)
2. **Project Settings -> Android**:
   - Set package name (replace placeholder)
   - Configure keystore for shipping builds
3. **Project Settings -> Rendering**:
   - Keep mobile-friendly defaults unless targeting high-end only
4. **Platforms -> Android -> Package Project** for test APK/AAB.

## Mobile performance direction (for "best" result)

For stable performance on Android:
- Prefer baked/static lighting where possible
- Keep draw calls low (merge meshes / use HLODs)
- Use texture compression correctly (ASTC)
- Limit dynamic shadows and post-processing
- Use simple materials for common assets
- Test on at least 3 real devices (low/mid/high tier)

## What is included

- Unreal project file: `OpenWorldMP.uproject`
- C++ game module with editor/game targets
- Custom GameMode + replicated GameState for main story stage
- Player character with camera boom + movement bindings
- Replicated quest component + quest struct/types
- Engine/input config defaults
- Production roadmap and beginner next steps

See `Docs/GAME_PLAN.md` for a production plan.
