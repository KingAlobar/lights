static Object SpawnObject(string type, vector position, vector orientation, float scale = 1.0)
{
    Object obj;
    if (type.Contains(".p3d")) {
        obj = GetGame().CreateStaticObjectUsingP3D(type, position, orientation, scale, false);
    } else {        
        obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_CREATEPHYSICS | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOPERSISTENCY_CHAR);
    }

    if (!obj) {
        Error("Failed to create object " + type);
        return null;
    }

    obj.SetPosition(position);
    obj.SetOrientation(orientation);
    obj.SetOrientation(obj.GetOrientation());
    obj.SetScale(scale);
    obj.Update();
	obj.SetAffectPathgraph(true, false);
	if (obj.CanAffectPathgraph()) {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
    } 

    return obj;
}

// Paste anything below this line into the bottom of your 'void main()' function


// Created Objects
SpawnObject("CivilianSedanFrontLight", "4217.435547 338.500946 10658.020508", "0.000000 0.000000 -0.000000", 1);
SpawnObject("CivilianSedanRearLight", "4230.890137 340.981537 10634.253906", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Hatchback_02FrontLight", "4410.687500 339.497284 10322.748047", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Hatchback_02RearLight", "4426.562988 342.717194 10303.198242", "0.000000 0.000000 -0.000000", 1);
SpawnObject("HeadtorchLight", "4435.550781 342.805664 10287.032227", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Offroad_02FrontLight", "4446.996582 339.638000 10263.777344", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Offroad_02RearLight", "4470.173828 340.553955 10227.875977", "0.000000 0.000000 -0.000000", 1);
SpawnObject("OffroadHatchbackFrontLight", "4483.525391 341.265900 10201.291992", "0.000000 0.000000 -0.000000", 1);
SpawnObject("OffroadHatchbackRearLight", "4502.590332 340.194885 10172.802734", "0.000000 0.000000 -0.000000", 1);
SpawnObject("PistollightLight", "4549.170898 340.294617 10090.208008", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Sedan_02FrontLight", "4633.812012 343.438873 9931.144531", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Sedan_02RearLight", "4651.150391 340.505524 9908.986328", "0.000000 0.000000 -0.000000", 1);
SpawnObject("SpotlightLight", "4678.093262 342.250427 9851.095703", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Truck_01FrontLight", "4764.763184 340.041321 9707.684570", "0.000000 0.000000 -0.000000", 1);
SpawnObject("Truck_01RearLight", "4773.733887 340.157227 9688.655273", "0.000000 0.000000 -0.000000", 1);
SpawnObject("UniversallightLight", "4787.470215 340.198669 9664.874023", "0.000000 0.000000 -0.000000", 1);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);
