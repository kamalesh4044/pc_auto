# OpenWorldMP (Unreal Engine 5 Starter)

This repository now contains a **complete starter foundation** for a third-person open-world Unreal game with:

- Story progression framework
- Quest state + progression logic
- Multiplayer-ready replication for core state
- Basic third-person character movement/input scaffolding

> You asked for "completely made" and "I don't know anything". This gives you a practical base you can open in Unreal and extend without starting from zero.

## What is included

- Unreal project file: `OpenWorldMP.uproject`
- C++ game module with editor/game targets
- Custom GameMode + replicated GameState for main story stage
- Player character with camera boom + movement bindings
- Replicated quest component + quest struct/types
- Engine/input config defaults
- Production roadmap and beginner next steps

## Quick start (beginner-friendly)

1. Install Unreal Engine 5.4 from Epic Games Launcher.
2. Generate C++ project files:
   - Windows: right-click `OpenWorldMP.uproject` -> **Generate Visual Studio project files**.
   - Linux/macOS: run Unreal's project generation command for your platform.
3. Open the project in Unreal Editor.
4. Create these content assets in `/Game`:
   - `Maps/OpenWorld_P` (a persistent world map)
   - `Blueprints/BP_OWPlayerCharacter` (child of `AOWPlayerCharacter`)
   - `UI/WBP_QuestTracker`
5. In Project Settings -> Maps & Modes:
   - Default GameMode = `AOWGameMode`
   - Default Pawn = `BP_OWPlayerCharacter`
6. Play in editor with:
   - 1 player for story flow testing
   - 2+ players (listen server) for multiplayer replication checks

## Story + multiplayer architecture (high level)

- `AOWGameMode` controls authoritative story progression.
- `AOWGameState` replicates the global story stage to all clients.
- `UOWQuestComponent` stores each player's quest states and replicates them.
- `AOWPlayerCharacter` is a third-person pawn with camera setup and core movement bindings.

## Suggested next milestones

- Add SaveGame support for story/quest persistence.
- Replace legacy axis mappings with Enhanced Input mapping contexts.
- Add dedicated server packaging profile.
- Add mission scripting via data assets + gameplay tags.
- Add world partition streaming regions for true large open-world scale.

See `Docs/GAME_PLAN.md` for a step-by-step production plan.
