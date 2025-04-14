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
SpawnObject("EntranceLight", "4242.375977 339.030212 10619.435547", "0.000000 0.000000 -0.000000", 1);
SpawnObject("EntranceLightMain1", "4248.516602 338.974182 10609.050781", "0.000000 0.000000 -0.000000", 1);
SpawnObject("EntranceLightMain2", "4253.707031 339.046906 10600.234375", "0.000000 0.000000 -0.000000", 1);
SpawnObject("EntranceLightStairs1", "4257.206055 339.850647 10593.815430", "0.000000 0.000000 -0.000000", 1);
SpawnObject("EntranceLightStairs2", "4262.602051 339.365082 10584.633789", "0.000000 0.000000 -0.000000", 1);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);
