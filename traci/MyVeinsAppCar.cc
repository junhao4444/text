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

#include "veins/modules/application/traci/MyVeinsAppCar.h"

using namespace veins;

Define_Module(veins::MyVeinsAppCar);

void MyVeinsAppCar::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        EV << "Initializing " << par("appName").stringValue() << std::endl;
        int a = INT_MIN;
    }
    else if (stage == 1) {
        RSUIndex.setName("test");
        int a = INT_MIN;
    }
}


void MyVeinsAppCar::finish()
{
    DemoBaseApplLayer::finish();
    // statistics recording goes here
}

void MyVeinsAppCar::onBSM(DemoSafetyMessage* bsm)
{
    // Your application has received a beacon message from another car or RSU
    // code for handling the message goes here
}

void MyVeinsAppCar::onWSM(BaseFrame1609_4* wsm)
{
    // Your application has received a data message from another car or RSU
    // code for handling the message goes here, see TraciDemo11p.cc for examples
}

void MyVeinsAppCar::onWSA(DemoServiceAdvertisment* wsa)
{
    // Your application has received a service advertisement from another car or RSU
    // code for handling the message goes here, see TraciDemo11p.cc for examples
}

void MyVeinsAppCar::handleLowerMsg(cMessage* msg) {
    EV << "receive message  !!!" << endl;
    //消息传换成WSM
    BaseFrame1609_4* WSM = check_and_cast<BaseFrame1609_4*>(msg);
    //从WSM中解封数据包
    cPacket* enc = WSM->getEncapsulatedPacket();
    //数据包转换成BeaconRSU
    BeaconRSU* bc = dynamic_cast<BeaconRSU*>(enc);

    if(a!=bc->getRSUId()){
       RSUIndex.record(bc->getRSUId());
       a=bc->getRSUId();
  }

  EV << "my message = " <<bc->getMyDemoData()<<endl;
  EV <<"send message RSU id:" <<bc->getRSUId() << "  Receive successfully !!!!!!!!!!!" << endl;
}

void MyVeinsAppCar::handleSelfMsg(cMessage* msg)
{
    DemoBaseApplLayer::handleSelfMsg(msg);
    // this method is for self messages (mostly timers)
    // it is important to call the DemoBaseApplLayer function for BSM and WSM transmission
}

void MyVeinsAppCar::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);
    // the vehicle has moved. Code that reacts to new positions goes here.
    // member variables such as currentPosition and currentSpeed are updated in the parent class
}
