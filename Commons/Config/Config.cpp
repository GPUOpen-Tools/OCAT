//
// Copyright(c) 2016 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include "Config.h"
#include "..\Utility\IniParser.h"
#include "..\Utility\FileUtils.h"
#include "..\Logging\MessageLog.h"
#include "..\Utility\ProcessHelper.h"

static std::wstring g_iniFile = L"settings.ini";

bool Config::Load(const std::wstring& path)
{
  const auto fileName = (path + g_iniFile);

  if (FileExists(fileName)) {
    hotkey_ = GetPrivateProfileInt(L"Recording", L"hotkey", hotkey_, fileName.c_str());
    toggleOverlayHotKey_ = GetPrivateProfileInt(L"Recording", L"toggleOverlayHotkey",
        toggleOverlayHotKey_, fileName.c_str());
    recordingTime_ = GetPrivateProfileInt(L"Recording", L"recordTime", recordingTime_, fileName.c_str());
    recordAllProcesses_ =
        ReadBoolFromIni(L"Recording", L"recordAllProcesses", recordAllProcesses_, fileName.c_str());
    g_messageLog.Log(MessageLog::LOG_INFO, "Config", "file loaded");
    return true;
  }
  else {
    g_messageLog.Log(MessageLog::LOG_WARNING, "Config",
                     "Unable to open config file. Using default values");
    return false;
  }
}