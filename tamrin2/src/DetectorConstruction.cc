#include "DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

DetectorConstruction::~DetectorConstruction()
{ }

G4VPhysicalVolume* DetectorConstruction::Construct()
{  
  G4NistManager* nist = G4NistManager::Instance(); //for use geant data
G4Material* mat1 = nist->FindOrBuildMaterial("G4_AIR"); //Definition of the first mat Air

// for definition of the secund mat we need to definition elements
G4Element* mat2C = nist->FindOrBuildElement("C"); //Definition of the first Element carbon
G4Element* mat2N = nist->FindOrBuildElement("N"); //Definition of the secund Element nitrogen
G4Element* mat2Fe = nist->FindOrBuildElement("Fe"); //Definition of the third element metal

//now we can definition mat to whit elemnts
G4String name;
G4int ncomponents;
G4double density,fractionmass ;
G4Material* mat2 = new G4Material(name = "mat2", density = 1.9 * g / cm3, ncomponents = 3);
mat2->AddElement(mat2C, fractionmass = 20 * perCent);
mat2->AddElement(mat2N, fractionmass = 30 * perCent);
mat2->AddElement(mat2Fe, fractionmass = 50 * perCent);


//The definition of geometry starts with the definition of the mother volume
G4Box* SBox = new G4Box("World", 1.*m, 1.*m, 1.*m);
G4LogicalVolume* LBox = new G4LogicalVolume(SBox, mat1, "World");
G4VPhysicalVolume* PBox = new G4PVPlacement(0, G4ThreeVector(), LBox, "World",0,false, 0);


G4Cons* Cons1 = new G4Cons("Cons1", 0 * cm, 0.5 * cm, 20* cm, 30 * cm, 30 * cm, 0 * deg, 360 * deg);
G4LogicalVolume* LCons1 = new G4LogicalVolume(Cons1, mat2, "Cons1");

G4RotationMatrix* rot = new G4RotationMatrix();
rot->rotateY(90 * deg);
G4VPhysicalVolume* PCons1 = new G4PVPlacement(rot, G4ThreeVector(0*cm,0*cm,20*cm), LCons1, "Cons1", LBox, false, 0);

//Definition the color of the cone
G4VisAttributes* vis = new G4VisAttributes();
vis->SetForceSolid(true);
vis->SetColor(250, 0, 0, 0.7);
LCons1->SetVisAttributes(vis);


return PBox;
}

