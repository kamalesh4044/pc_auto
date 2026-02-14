# Game Plan: Third-Person Open-World Story + Multiplayer (Unreal)

## 1) Core game fantasy

**Title (working):** Echoes of the Shattered Vale  
**Genre:** Third-person action RPG  
**Modes:** Single-player story + drop-in cooperative multiplayer

### Player loop

1. Explore open world region.
2. Discover dynamic events and story objectives.
3. Fight enemies / complete objectives.
4. Earn progression unlocks.
5. Advance main story chapter.

## 2) MVP scope (first playable)

- One explorable open-world zone.
- One hub settlement with NPC dialogue.
- 3 main story quests (chapter 1).
- 5 side quests.
- Co-op support for up to 4 players.
- Shared world state for main chapter progression.

## 3) System breakdown

### Story system

- Server-authoritative chapter index in `AOWGameMode`.
- Replicated to clients through `AOWGameState`.
- Chapter updates trigger world-state changes (NPC availability, events).

### Quest system

- Per-player quest states in `UOWQuestComponent`.
- Each quest has:
  - `QuestId`
  - `Status`
  - `CurrentStep`
- Replication supports co-op visibility and UI sync.

### Multiplayer

- Listen server for quick iteration.
- Dedicated server target later in production.
- Replicate only essential states first (story index, quest steps, combat states).
- Add prediction/reconciliation for movement/combat as complexity grows.

## 4) Content pipeline

- Use World Partition for terrain streaming.
- Build quests from DataAssets and tables.
- Keep scripted mission logic in modular components, not in level blueprint.
- Create "vertical slice" area before scaling world size.

## 5) Beginner workflow in Unreal (do this order)

1. Get movement and camera feeling good.
2. Add one enemy archetype and simple combat.
3. Create one complete quest from start -> finish.
4. Add co-op and verify replication for quest completion.
5. Add UI for chapter + active quest objective.
6. Expand map size only after above is stable.

## 6) Definition of done for alpha

- Players can join/leave co-op without breaking chapter progression.
- Main story chapter completes reliably in networked sessions.
- Quest UI updates are consistent on all clients.
- Stable 60 FPS on target hardware in MVP zone.
