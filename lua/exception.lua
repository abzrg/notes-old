-- [ Lua and exception ] --------------------------------------------

--  Raise with `error()`, `assert()`, `lua_error()`
--  Catch with `pcall()`

-- Note that:
--  - There is no try-except construct
--  - Error object not limited to strings
--  - It is implemented with C `longjmp()`

-- Exception mainly used for obvious programming errors
--  - parse error
--  - type errors
--  - invalid function arguments
-- Notable departure: `require()`, `dofile()`
-- Exclusively string error objects


-- [ The nil-error protocol] -------------------------------------------

-- On error, function returns `[nil, error, message]` tuple
-- Made popular by Lua standard libs
-- Issues:
--  - not checking can result in delayed, secondary error
--  - what if `nil` is a valid output?
-- Can use `assert()` to convert to exception


-- [try-except definition] -------------------------------------------

-- `try(f, catch_f)`
--  - Executes function `f`, and if an exception results, then `catch_f` is
--    called with the error object
-- Differs from `xpcall()`
--  - Propagates exceptions, rather than returning nil-error
--  - Error-handler supports nested errors


-- [Implementation and usage] -------------------------------------------

function try(f, catch_f)
    local status, exception = pcall(f)
    if not status then
        catch_f(exception)
    end
end

try(function()
    -- Try block
end, function(e)
    -- Except block. E.g.:
    --  - Use e for conditional catch
    --  - reraise with error(e)
end)


-- [Custom exception objects] --------------------------------------------

error({code=121})


-- [Uncaught table] ------------------------------------------------

-- > error({code=121})
-- (error object is not a string)

-- A Better error object
SomethingBad = {code=121, msg = 'Oops' }


-- [lua.org] -----------------------------------------------------

-- Put your chunk of code that creates any kind of error or exception in
-- a function
function foo ()
    -- ...
  if unexpected_condition then error() end
    -- ...
  print(a[i])    -- potential error: `a' may not be a table
    -- ...
end


-- The call foo with pcall
if pcall(foo) then
  -- no errors while running `foo'
  -- ...
else
  -- `foo' raised an error: take appropriate actions
  -- ...
end


-- Alternatively you can use an anonymous

if pcall(function () --[[ ... ]] end) then --[[ ... ]]
else --[[ ... ]]
end
