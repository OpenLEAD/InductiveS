/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"
#include "EthernetDrivers/EthernetDrivers.hpp"

using namespace inductive;

Task::Task(std::string const& name)
    : TaskBase(name)
    , InductiveS(0)
{
  unsigned char t_mac[6];
  t_mac[0]=0x00;
  t_mac[1]=0x04;
  t_mac[2]=0xA3;
  t_mac[3]=0x31;
  t_mac[4]=0x00;
  t_mac[5]=0x14;
  char bdip[]="192.168.1.255";

	InductiveS = new EthernetDrivers::GPIOin_Driver(bdip,t_mac,5);
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine)
    : TaskBase(name, engine)
    , InductiveS(0)
{
  unsigned char t_mac[6];
  t_mac[0]=0x00;
  t_mac[1]=0x04;
  t_mac[2]=0xA3;
  t_mac[3]=0x31;
  t_mac[4]=0x00;
  t_mac[5]=0x14;
  char bdip[]="192.168.1.255";

	InductiveS = new EthernetDrivers::GPIOin_Driver(bdip,t_mac,5);
}

Task::~Task()
{
	delete InductiveS;
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See Task.hpp for more detailed
// documentation about them.

bool Task::configureHook()
{
    if (! TaskBase::configureHook())
        return false;
    return true;
}
bool Task::startHook()
{
    if (! TaskBase::startHook())
        return false;
    return true;
}
void Task::updateHook()
{
    bool msg;
    InductiveS->read(&msg);
    TaskBase::updateHook();
//_input.readNewest();
    _output.write(msg);
}
void Task::errorHook()
{
    TaskBase::errorHook();
}
void Task::stopHook()
{
    TaskBase::stopHook();
}
void Task::cleanupHook()
{
    TaskBase::cleanupHook();
}
