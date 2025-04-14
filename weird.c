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
SpawnObject("AnniversaryBoxLight", "4139.998047 339.397827 10801.085938", "0.000000 0.000000 -0.000000", 1);
SpawnObject("AnniversaryMainLight", "4145.291992 340.378906 10791.383789", "0.000000 0.000000 -0.000000", 1);
SpawnObject("BlowtorchLight", "4159.860840 339.185059 10770.694336", "0.000000 0.000000 -0.000000", 1);
SpawnObject("BrightnessTestLight", "4192.310547 340.872467 10708.338867", "0.000000 0.000000 -0.000000", 1);
SpawnObject("ChemlightLight", "4206.682617 340.908508 10682.375977", "0.000000 0.000000 -0.000000", 1);
SpawnObject("GoatLight", "4397.553223 339.068451 10345.023438", "0.000000 0.000000 -0.000000", 1);
SpawnObject("PartyLight", "4518.233398 342.958466 10142.041016", "0.000000 0.000000 -0.000000", 1);
SpawnObject("PortableGasLampLight", "4568.409180 339.326599 10054.473633", "0.000000 0.000000 -0.000000", 1);
SpawnObject("StoveLight", "4720.233398 338.980499 9786.053711", "0.000000 0.000000 -0.000000", 1);
SpawnObject("XmasSleighLight", "4798.958008 339.841156 9645.358398", "0.000000 0.000000 -0.000000", 1);
SpawnObject("XmasTreeLight", "4820.238281 341.180084 9614.388672", "0.000000 0.000000 -0.000000", 1);
SpawnObject("ZombieMummyLight", "4802.045410 339.842621 9601.311523", "0.000000 0.000000 -0.000000", 1);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);
