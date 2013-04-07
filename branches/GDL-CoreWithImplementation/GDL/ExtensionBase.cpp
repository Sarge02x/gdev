/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */

#include <vector>
#include <string>
#include <iostream>
#include "GDL/ExtensionBase.h"
#include "GDL/Automatism.h"
#include "GDL/AutomatismsSharedData.h"
#include "GDL/CommonTools.h"
#if defined(GD_IDE_ONLY)
#include "GDCore/Events/Event.h"
#endif

using namespace std;

std::map<std::string, ExtensionObjectInfos > ExtensionBase::badObjectsInfos;
std::map<std::string, AutomatismInfo > ExtensionBase::badAutomatismsInfo;

#if defined(GD_IDE_ONLY)
std::map<std::string, gd::InstructionMetadata > ExtensionBase::badConditionsInfos;
std::map<std::string, gd::InstructionMetadata > ExtensionBase::badActionsInfos;
std::map<std::string, gd::ExpressionMetadata > ExtensionBase::badExpressionsInfos;
std::map<std::string, gd::StrExpressionMetadata > ExtensionBase::badStrExpressionsInfos;
#endif

ExtensionObjectInfos::ExtensionObjectInfos() :
destroyFunPtr(NULL),
createFunPtr(NULL)
{
}

#if defined(GD_IDE_ONLY)

EventInfos::EventInfos() :
instance(boost::shared_ptr<gd::BaseEvent>())
{
}
#endif

AutomatismInfo::AutomatismInfo() :
instance(boost::shared_ptr<Automatism>())
{
}

AutomatismInfo::~AutomatismInfo()
{
}

void ExtensionBase::SetNameSpace(std::string nameSpace_)
{
    //For backward compatibility
    //or for extension without namespace
    if (name == "Sprite" ||
        name == "BuiltinObject" ||
        name == "BuiltinAudio" ||
        name == "BuiltinMouse" ||
        name == "BuiltinKeyboard"||
        name == "BuiltinJoystick" ||
        name == "BuiltinTime"||
        name == "BuiltinFile"||
        name == "BuiltinInterface"||
        name == "BuiltinVariables"||
        name == "BuiltinCamera"||
        name == "BuiltinWindow"||
        name == "BuiltinNetwork"||
        name == "BuiltinScene"||
        name == "BuiltinAdvanced" ||
        name == "BuiltinCommonConversions" ||
        name == "BuiltinStringInstructions" ||
        name == "BuiltinMathematicalTools" ||
        name == "CommonDialogs") //New name for BuiltinInterface
    {
        nameSpace = "";
        return;
    }


    nameSpace = nameSpace_+"::";
}

vector < std::string > ExtensionBase::GetExtensionObjectsTypes() const
{
    vector < string > objects;

    std::map<string, ExtensionObjectInfos>::const_iterator it;
    for(it = objectsInfos.begin(); it != objectsInfos.end(); ++it)
        objects.push_back(it->first);

    return objects;
}

#if defined(GD_IDE_ONLY)
vector < std::string > ExtensionBase::GetAutomatismsTypes() const
{
    vector < string > automatisms;

    std::map<string, AutomatismInfo>::const_iterator it;
    for(it = automatismsInfo.begin(); it != automatismsInfo.end(); ++it)
        automatisms.push_back(it->first);

    return automatisms;
}

const std::map<std::string, gd::InstructionMetadata > & ExtensionBase::GetAllActions() const
{
    return actionsInfos;
}

const std::map<std::string, gd::InstructionMetadata > & ExtensionBase::GetAllConditions() const
{
    return conditionsInfos;
}

const std::map<std::string, gd::ExpressionMetadata > & ExtensionBase::GetAllExpressions() const
{
    return expressionsInfos;
}

const std::map<std::string, gd::StrExpressionMetadata > & ExtensionBase::GetAllStrExpressions() const
{
    return strExpressionsInfos;
}

const std::map<std::string, EventInfos > & ExtensionBase::GetAllEvents() const
{
    return eventsInfos;
}

const std::map<std::string, AutomatismInfo > & ExtensionBase::GetAllAutomatisms() const
{
    return automatismsInfo;
}
const std::map<std::string, gd::InstructionMetadata > & ExtensionBase::GetAllActionsForObject(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.actionsInfos;

    return badActionsInfos;
}

const std::map<std::string, gd::InstructionMetadata > & ExtensionBase::GetAllConditionsForObject(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.conditionsInfos;

    return badConditionsInfos;
}

const std::map<std::string, gd::ExpressionMetadata > & ExtensionBase::GetAllExpressionsForObject(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.expressionsInfos;

    return badExpressionsInfos;
}

const std::map<std::string, gd::StrExpressionMetadata > & ExtensionBase::GetAllStrExpressionsForObject(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.strExpressionsInfos;

    return badStrExpressionsInfos;
}

const std::map<std::string, gd::InstructionMetadata > & ExtensionBase::GetAllActionsForAutomatism(std::string autoType) const
{
    if ( automatismsInfo.find(autoType) != automatismsInfo.end())
        return automatismsInfo.find(autoType)->second.actionsInfos;

    return badActionsInfos;
}

const std::map<std::string, gd::InstructionMetadata > & ExtensionBase::GetAllConditionsForAutomatism(std::string autoType) const
{
    if ( automatismsInfo.find(autoType) != automatismsInfo.end())
        return automatismsInfo.find(autoType)->second.conditionsInfos;

    return badConditionsInfos;
}

const std::map<std::string, gd::ExpressionMetadata > & ExtensionBase::GetAllExpressionsForAutomatism(std::string autoType) const
{
    if ( automatismsInfo.find(autoType) != automatismsInfo.end())
        return automatismsInfo.find(autoType)->second.expressionsInfos;

    return badExpressionsInfos;
}

const std::map<std::string, gd::StrExpressionMetadata > & ExtensionBase::GetAllStrExpressionsForAutomatism(std::string autoType) const
{
    if ( automatismsInfo.find(autoType) != automatismsInfo.end())
        return automatismsInfo.find(autoType)->second.strExpressionsInfos;

    return badStrExpressionsInfos;
}

const ExtensionObjectInfos & ExtensionBase::GetObjectMetadata(const std::string & objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second;

    return badObjectsInfos[""];
}

const AutomatismInfo & ExtensionBase::GetAutomatismMetadata(const std::string & automatismType) const
{
    if ( automatismsInfo.find(automatismType) != automatismsInfo.end())
        return automatismsInfo.find(automatismType)->second;

    return badAutomatismsInfo[""];
}
#endif

CreateFunPtr ExtensionBase::GetObjectCreationFunctionPtr(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.createFunPtr;

    return NULL;
}

DestroyFunPtr ExtensionBase::GetDestroyObjectFunction(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.destroyFunPtr;

    return NULL;
}

CreateRuntimeObjectFunPtr ExtensionBase::GetRuntimeObjectCreationFunctionPtr(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.createRuntimeObjectFunPtr;

    return NULL;
}

DestroyRuntimeObjectFunPtr ExtensionBase::GetDestroyRuntimeObjectFunction(std::string objectType) const
{
    if ( objectsInfos.find(objectType) != objectsInfos.end())
        return objectsInfos.find(objectType)->second.destroyRuntimeObjectFunPtr;

    return NULL;
}


#if defined(GD_IDE_ONLY)
gd::BaseEventSPtr ExtensionBase::CreateEvent(std::string eventType) const
{
    if ( eventsInfos.find(eventType) != eventsInfos.end())
        return eventsInfos.find(eventType)->second.instance->Clone();

    return boost::shared_ptr<gd::BaseEvent>();
}
#endif

Automatism* ExtensionBase::CreateAutomatism(std::string type) const
{
    if ( automatismsInfo.find(type) != automatismsInfo.end())
        return automatismsInfo.find(type)->second.instance->Clone();

    return NULL;
}


boost::shared_ptr<gd::AutomatismsSharedData> ExtensionBase::CreateAutomatismSharedDatas(std::string type) const
{
    if ( automatismsInfo.find(type) != automatismsInfo.end())
        return automatismsInfo.find(type)->second.sharedDatasInstance->Clone();

    return boost::shared_ptr<gd::AutomatismsSharedData>();
}

void ExtensionBase::SceneLoaded(RuntimeScene & scene)
{
}

void ExtensionBase::SceneUnloaded(RuntimeScene & scene)
{
}

