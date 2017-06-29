#pragma once

#include "Common.h"
#include "BWAPI.h"
#include "../../SparCraft/source/SparCraft.h"
#include "ArenaPlayer.h"

namespace UAlbertaBot
{
    
class ArenaPlayer_SparCraft : public ArenaPlayer
{
    SparCraft::GameState    GetSparCraftState() const;
    SparCraft::Unit         GetSparCraftUnit(BWAPI::Unit unit) const;
    SparCraft::Move         GetSparCraftPlayerMove(const SparCraft::GameState & state, const size_t & playerID) const;
    size_t                  GetSparCraftPlayerID(BWAPI::Player player) const;
    void                    DoSparCraftMove(const SparCraft::GameState & state, const SparCraft::Move & move) const;
    void                    DrawSparCraftState(const SparCraft::GameState & state, int x, int y) const;
    void                    DrawSparCraftMove(const SparCraft::GameState & state, const SparCraft::Move & move) const;

    int                     GetTimeSinceLastAttack(BWAPI::Unit unit) const;
    int                     GetTimeCanAttack(BWAPI::Unit unit) const;
    int                     GetTimeCanMove(BWAPI::Unit unit) const;

    void                    PlaySparCraftSimulation(const SparCraft::GameState & state);

public:

	ArenaPlayer_SparCraft();

    void onStart();
    void onFrame();
    void onBattleBegin();
    void onBattleEnd();
};
}