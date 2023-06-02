#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"

class G4GeneralParticleSource;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event*);

  private:

    G4GeneralParticleSource*  fGeneralParticleSource;
};

#endif
