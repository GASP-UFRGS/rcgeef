#include "ActionInitialization.hh"
#if (G4VERSION_NUMBER >= 1000)
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"


ActionInitialization::ActionInitialization()
: G4VUserActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::BuildForMaster() const
{

}

void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);
}
#endif