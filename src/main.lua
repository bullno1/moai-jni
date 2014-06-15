print("Hello world")

System = luajava.bindClass("java.lang.System")
print("Current time:", System:currentTimeMillis())


-- A module loader for java classes
local function javaLoader(javaClass)
	local success, resultOrError = pcall(luajava.bindClass, javaClass)
	if success then
		return function() return resultOrError end
	else
		return "\n\tno Java class '"..javaClass.."'"
	end
end
table.insert(package.loaders, javaLoader)

-- Make a toast for luajava
Toast = require "android.widget.Toast" -- just require it
MoaiActivity = require "ch.levietba.moaijni.MoaiActivity"
local appCtx = MoaiActivity:getCurrentInstance():getApplicationContext()
local duration = Toast.LENGTH_LONG
text = Toast:makeText(appCtx, "Hello world from JNI", duration)
text:show()

-- Do things we couldn't trivially do before
Environment = require "android.os.Environment"
print("SD card path:", Environment:getExternalStorageDirectory():toString())

-- Let's crash
require "somethingsomething"
