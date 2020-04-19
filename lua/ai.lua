
-- -- Getter des divers param du plateau de jeu

function getSize(mapLength, mapWidth)
   length = mapLength
   width = mapWidth
end

function getString(string)
   map = string
end

function getPlayer(x, y, bomb)
   pos_x = x
   pos_y = y
   nbr_bomb = bomb
end

boxList = nil
bombList = nil
bonusList = nil
playerList = nil

function addBomb(x, y, range)
   bombList = {next = bombList, bomb = {pos_x = x + 1, pos_y = y, range = range}}
end

function addPlayer(x, y)
   playerList = {next = playerList, player = {pos_x = x, pos_y = y}}
end

function addBonus(x, y)
   bonusList = {next = bonusList, bonus = {pos_x = x, pos_y = y}}
end

function addBox(x, y)
   boxList = {next = boxList, box = {pos_x = x, pos_y = y}}
end

-- Parametres de déplacements

up = 0
down = 0
left = 0
right = 0

function addValue(toAdd)
   if toAdd == 'w'
   then
      return -1
   end
   if toAdd == 'd'
   then
      return -4
   end
   if toAdd == 'p'
   then
      return 1
   end
   if toAdd == 'u'
   then
      return 2
   end
end

-- Deplacements

function goSafe(lvl, c_x, c_y)
   if lvl < 3 and (c_y - 1) >= 0 and up ~= nil		-- UP
   then
      if string.sub(map, c_x + ((c_y - 1) * length), c_x + ((c_y - 1) * length)) == "w" and lvl == 1
      then
	 up = nil
      else
	 up = up + addValue(string.sub(map, c_x + ((c_y - 1) * length), c_x + ((c_y - 1) * length)))
	 if string.sub(map, c_x + ((c_y - 1) * length), c_x + ((c_y - 1) * length)) ~= "w"
	 then
	    goSafe(lvl + 1, c_x, c_y - 1)
	 end
      end
   end
   
   if lvl < 3 and (c_x - 1) >= 0		-- LEFT
   then
      if string.sub(map, (c_x - 1) + (c_y * length), (c_x - 1) + (c_y * length)) == "w" and lvl == 1
      then
	 left = nil
      else
	 addValue(left, string.sub(map, (c_x - 1) + (c_y * length), (c_x - 1) + (c_y * length)))
	 if string.sub(map, (c_x - 1) + (c_y * length), (c_x - 1) + (c_y * length)) ~= "w"
	 then
	    goSafe(lvl + 1, c_x - 1, c_y)
	 end
      end
   end

   if lvl < 3 and (c_x + 1) >= 0		-- RIGTH
   then
      if string.sub(map, (c_x + 1) + (c_y * length), (c_x + 1) + (c_y * length)) == "w" and lvl == 1
      then
	 rigth = nil
      else
	 addValue(rigth, string.sub(map, (c_x + 1) + (c_y * length), (c_x + 1) + (c_y * length)))
	 if string.sub(map, (c_x + 1) + (c_y * length), (c_x + 1) + (c_y * length)) ~= "w"
	 then
	    goSafe(lvl + 1, c_x + 1, c_y)
	 end
      end
   end

   if lvl < 3 and (c_y + 1) < width		-- DOWN
   then
      if string.sub(map, c_x + ((c_y + 1) * length), c_x + ((c_y + 1) * length)) == "w" and lvl == 1
      then
	 down = nil
      else
	 addValue(down, string.sub(map, c_x + ((c_y + 1) * length), c_x + ((c_y + 1) * length)))
	 if string.sub(map, c_x + ((c_y + 1) * length), c_x + ((c_y + 1) * length)) ~= "w"
	 then
	    goSafe(lvl + 1, c_x, c_y + 1)
	 end
      end
   end
end

function maxParam()
   local res = 1
   local maxValue = right

   print("right : "..right.."; left : "..left.."; up : "..up.."; down : "..down..";")
   if maxValue < left
   then
      res = 2
      maxValue = left
   end
   if maxValue < up
   then
      res = 3
      maxVaLue = up
   end
   if maxValue < down
   then
      res = 4
   end
   return res
end

function moveBot()
   goSafe(0, pos_x, pos_y)
   return maxParam()
end

-- Fonctions placement eds objets dans la map

function addHazardPos(bomb)
   local count = bomb.range

   while count > -(bomb.range + 1) do
      if string.sub(map, (bomb.pos_x + count) + (bomb.pos_y * length), (bomb.pos_x + count) + (bomb.pos_y * length)) ~= "w" and ((bomb.pos_x + count) > 0 and (bomb.pos_x + count) < length)
      then
	 map = string.sub(map, 1, ((bomb.pos_x + count) + (bomb.pos_y * length)) - 1)..'d'..string.sub(map, ((bomb.pos_x + count) + (bomb.pos_y * length)) + 1)
      end
      count = count - 1
   end

   count = count + 1

   while count < (bomb.range + 1) do
      if string.sub(map, (bomb.pos_x + ((bomb.pos_y + count) * length)), (bomb.pos_x + ((bomb.pos_y + count) * length))) ~= "w" and ((bomb.pos_y + count) >= 0 and (bomb.pos_y + count) < width)
      then
	 map = string.sub(map, 1, (bomb.pos_x + ((bomb.pos_y + count) * length)) - 1)..'d'..string.sub(map, (bomb.pos_x + ((bomb.pos_y + count) * length)) + 1)
      end
      count = count + 1
   end
end

function placeBonus()
   while bonusList ~= nil do
      map = map:sub(1, (bonusList.bonus.pos_x + (bonusList.bonus.pos_y * length)) - 1)..'u'..map:sub((bonusList.bonus.pos_x + (bonusList.bonus.pos_y * length)) + 1)
      bonusList = bonusList.next
   end
end

function placePlayer()
   while playerList ~= nil do
      map = map:sub(1, ((playerList.player.pos_x + 1) + (playerList.player.pos_y * length)) - 1)..'p'..map:sub(((playerList.player.pos_x + 1) + (playerList.player.pos_y * length)) + 1)
      playerList = playerList.next
   end
end

function placeBox()
   while boxList ~= nil do
      map = map:sub(1, (boxList.box.pos_x + (boxList.box.pos_y * length)) - 1)..'x'..map:sub((boxList.box.pos_x + (boxList.box.pos_y * length)) + 1)
      boxList = boxList.next
   end
end

function placeBomb()
   while bombList ~= nil do
      addHazardPos(bombList.bomb)
      bombList = bombList.next
   end
end

-- function dumpMap()
--    local count = 1

--    while count <= map:len() do
--       io.write(string.sub(map, count, count));
--       if count % length == 0
--       then
-- 	 io.write("\n")
--       end
--       count = count + 1;
--    end
--    io.write("\n--------------------------------------------\n");
-- end

function updateMap()
   placeBonus()
   placeBox()
   placePlayer()
   placeBomb()
end
