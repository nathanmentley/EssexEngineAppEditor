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

#include <EssexEngineAppEditor/PackageGameWindow.h>

EssexEngine::Apps::Editor::Windows::PackageGameWindow::PackageGameWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close) {
}

EssexEngine::Apps::Editor::Windows::PackageGameWindow::~PackageGameWindow()
{
}

void EssexEngine::Apps::Editor::Windows::PackageGameWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::PackageGameWindow::Render() {
    ImGui::Begin("Package Game");
    
    ImGui::Text("Packaging wizard is wip.");
    ImGui::Text("Compress the content folder manually for now and bundle with engine builds for the target.");
    ImGui::Text("I'm guessing I'll have the editor build the archive and setup packages for each target automatically.");
    
    if(ImGui::Button("Close")) {
        close();
    }
    ImGui::End();
}
