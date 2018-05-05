/* 
 * Essex Engine
 * 
 * Copyright (C) 2017 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */
#pragma once

#include <EssexEngineCore/BaseApp.h>
#include <EssexEngineAppEditor/EditorMainState.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
    class EditorApp: public Core::BaseApp
    {
        public:
            EditorApp(WeakPointer<Context> context): BaseApp(),
                initState(UniquePointer<EditorMainState>(new EditorMainState(context))) {}
            ~EditorApp() {}
            std::string GetAppName() { return "Editor"; }
            std::string GetAppVersion() { return ESSEX_ENGINE_VERSION; }
            WeakPointer<Core::Models::IState> GetInitState() { return initState.ToWeakPointer().Cast<Core::Models::IState>(); };
        private:
            UniquePointer<EditorMainState> initState;
    };
}}};
