#include "PhysicsList.hh"
#include "G4SystemOfUnits.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

PhysicsList::PhysicsList()
: G4VModularPhysicsList(){
  SetVerboseLevel(4);
  defaultCutValue = 10.0*um;

  RegisterPhysics(new G4DecayPhysics());
  RegisterPhysics(new G4RadioactiveDecayPhysics());
  RegisterPhysics(new G4EmLivermorePhysics());
}
PhysicsList::~PhysicsList()
{ 
}
void PhysicsList::SetCuts()
{
  G4VUserPhysicsList::SetCuts();
}  
