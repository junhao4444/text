//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/modules/application/traci/MyVeinsAppRSU.h"

using namespace veins;

Define_Module(veins::MyVeinsAppRSU);

void MyVeinsAppRSU::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        EV << "Initializing " << par("appName").stringValue() << std::endl;
        int a = INT_MIN;
    }
    else if (stage == 1) {
        if (sendBeacon->isScheduled()) {
              cancelEvent(sendBeacon);
       }
       scheduleAt(simTime()+5,sendBeacon);
    }
}



void MyVeinsAppRSU::finish()
{
    DemoBaseApplLayer::finish();
    // statistics recording goes here
}

void MyVeinsAppRSU::onBSM(DemoSafetyMessage* bsm)
{
    // Your application has received a beacon message from another car or RSU
    // code for handling the message goes here
}

void MyVeinsAppRSU::onWSM(BaseFrame1609_4* wsm)
{
    // Your application has received a data message from another car or RSU
    // code for handling the message goes here, see TraciDemo11p.cc for examples
}

void MyVeinsAppRSU::onWSA(DemoServiceAdvertisment* wsa)
{
    // Your application has received a service advertisement from another car or RSU
    // code for handling the message goes here, see TraciDemo11p.cc for examples
}

void MyVeinsAppRSU::handleSelfMsg(cMessage* msg)
{
    if (msg == sendBeacon) {

           BeaconRSU* rsuBeacon = new BeaconRSU();
           rsuBeacon->setRSUId(this->getParentModule()->getIndex());
           rsuBeacon->setMyDemoData("RSU message!!");
//          新建WSM，这是应用层和MAC层通信的消息
           BaseFrame1609_4* WSM = new BaseFrame1609_4();
           //把rsuBeacon封装在WSM中
           WSM->encapsulate(rsuBeacon);
           //设置WSM的基本信息
           populateWSM(WSM);
           send(WSM,lowerLayerOut);
           EV << "rsu send success" <<endl;
           if (simTime() < 2000) {
               scheduleAt(simTime()+1,sendBeacon);
           }
           return;
       }
}


void MyVeinsAppRSU::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);
    // the vehicle has moved. Code that reacts to new positions goes here.
    // member variables such as currentPosition and currentSpeed are updated in the parent class
}
