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

#include <functional>

#include <EssexEngineCore/Context.h>
#include <EssexEngineJsonDaemon/IJsonDocument.h>

#include <EssexEngineAppEditor/Daemons.h>

namespace EssexEngine{
namespace Apps{
namespace Editor{
namespace Windows{
    class IEditorWindow
    {
    public:
        IEditorWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close) {
            context = _context;
            gameDocument = _gameDocument;
            close = _close;
        }
    protected:
        WeakPointer<Context> context;
        WeakPointer<Daemons::Json::IJsonDocument> gameDocument;
        std::function<void()> close;
    };
}}}};
