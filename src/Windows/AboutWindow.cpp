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
 
#include <EssexEngineAppEditor/AboutWindow.h>

EssexEngine::Apps::Editor::Windows::AboutWindow::AboutWindow(WeakPointer<Context> _context, WeakPointer<Daemons::Json::IJsonDocument> _gameDocument, std::function<void()> _close)
:IEditorWindow(_context, _gameDocument, _close),
    tempWindow(
        _context->GetDaemon<Daemons::Window::WindowDaemon>()->CreateWindow(
            Daemons::Window::WindowDef(
                "About Essex Engine Editor - 0.0.1",
                0,
                0,
                400,
                400,
                std::bind(&AboutWindow::ButtonClick, this)
            )
        )
    )
{
    Daemons::Window::LabelDef label = Daemons::Window::LabelDef();
    label.Content = "%s Game Editor Build %x";
    label.X = 0;
    label.Y = 0;
    label.Width = 400;
    label.Height = 300;
    context->GetDaemon<Daemons::Window::WindowDaemon>()->AddLabel(tempWindow.ToWeakPointer(), label);
    
    Daemons::Window::ButtonDef button = Daemons::Window::ButtonDef();
    button.Title = "button title";
    button.X = 10;
    button.Y = 310;
    button.Width = 380;
    button.Height = 80;
    button.OnClick = std::bind(&AboutWindow::ButtonClick, this);
    context->GetDaemon<Daemons::Window::WindowDaemon>()->AddButton(tempWindow.ToWeakPointer(), button);
}

EssexEngine::Apps::Editor::Windows::AboutWindow::~AboutWindow() {
    context->GetDaemon<Daemons::Window::WindowDaemon>()->CloseWindow(tempWindow.ToWeakPointer());
}

void EssexEngine::Apps::Editor::Windows::AboutWindow::Logic() {
}

void EssexEngine::Apps::Editor::Windows::AboutWindow::Render() {
}

void EssexEngine::Apps::Editor::Windows::AboutWindow::WindowClose() {
    close();
}

void EssexEngine::Apps::Editor::Windows::AboutWindow::ButtonClick() {
    close();
}
