#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSMessage.hpp"
#include "Common.hpp"
#include "API/CExoLocString.hpp"
#include "ViewPtr.hpp"

#include <unordered_map>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Rename {

class Rename : public NWNXLib::Plugin
{
public:
  Rename(const Plugin::CreateParams& params);
  virtual ~Rename();
  
private:
  
  NWNXLib::Hooking::FunctionHook* m_SendServerToPlayerPlayerList_All;
  NWNXLib::Hooking::FunctionHook* m_HandlePlayerToServerParty;
  
  static int32_t HookPlayerList(NWNXLib::API::CNWSMessage* message, NWNXLib::API::CNWSPlayer* pPlayer);
  static int32_t HookPartyInvite(NWNXLib::API::CNWSMessage* message, NWNXLib::API::CNWSPlayer* pPlayer, unsigned char c);
  NWNXLib::API::CExoLocString ContainString(std::string str);
  std::string ExtractString(NWNXLib::API::CExoLocString locStr);
  void GlobalNameChange(bool bOriginal);
  void UpdateName(NWNXLib::API::CNWSCreature* targetObject);
  ArgumentStack SetPlayerNameOverride(ArgumentStack&& args);
   
  NWNXLib::API::CNWSPlayer *player(NWNXLib::API::Types::ObjectID playerId);
};
 
}