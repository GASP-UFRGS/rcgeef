#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1


#include "G4VUserDetectorConstruction.hh"
#include "G4Version.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"


class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        DetectorConstruction();
        virtual ~DetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

        virtual void ConstructSDandField();
       

    private:
        void DefineMaterials();
        
        // world
        G4LogicalVolume* logicWorld;
        G4VPhysicalVolume* physWorld;
        
        // target
        G4Box* solidTarget;
        G4LogicalVolume* logicTarget;
        G4VPhysicalVolume* physTarget;

        // Materials
        G4Material* worldMaterial;
        G4Material* targetMaterial;
        G4Material* Air;



};
#endif