/**
 * Copyright (C) 2016-2020 Xilinx, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef HAL_PLUGIN_DOT_H
#define HAL_PLUGIN_DOT_H

#include <vector>
#include <set>
#include "xdp/profile/plugin/vp_base_plugin.h"

namespace xdp {

  // Forward declarations
  class DeviceIntf ; 

  class HALPlugin : public XDPPlugin
  {
  private:
    std::vector<DeviceIntf*> devices ;
    std::set<void*> encounteredHandles ;

    void flushDevices() ;
    void continuousOffload() ;
  public:
    HALPlugin() ;
    ~HALPlugin() ;

    virtual void writeAll(bool openNewFiles) ;
    virtual void readDeviceInfo(void* device) ;
    void flushDeviceInfo(void* device) ;
    void setEncounteredDeviceHandle(void* handle) ;
  } ;

}

#endif
