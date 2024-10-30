# Angry AI
## Game for Wierd game jam #6
#### Made in Mikicrep Game Engine (MCGE)

### What is game about?
Game is about killing AIs
It is turn based game
First you attack AI then AIs attack you and then it repeats

Player got 1500 HP and you cannot increase it in any way, it gets healed every time you beat level

### Attacking guide
#### Basic attacking
When you spawn, you can click anywhere on map to launch projectile towards cursor
Gravity will pull it down so you have to aim
Once you hit enemy, enemy gets damaged and then AIs attack you
If you miss all AIs, you wont loose your turn
If you hit spot where AI died then you loose your turn
#### Special attacking
Special bar fills up by hitting AI
Once bar below player fills up you can attack enemies using right click
When you right click on enemy (no aiming needed, just put cursor over it) your special bar will be drained and enemy will recieve 100 damage and you wont loose your turn

### Defending guide
You defending is automatic, but you should keep in mind some things so you can make good strategy:
#### Attacking
All AIs have same attack damage `AIs[x].damage = 50 * (1 + (.05 * level));`
#### Specials
Special bar fills up every successful attack, each AI got its own special attack:
##### GPT
Each 4 successful attacks, GPT spawns 2 shields on random spots (can also spawn 1 shield if both shields are on same spot)
Shields cannot be penetrated so you have to destroy them or do trickshot to kill AI without touching shield
##### Copilot
Each 3 successful attacks, Copilot deals exactly 100 damage to player
##### Gemini
Each 4 successful attacks, Gemini deals betweeen 0 and 200 damage
It can be deadliest AI out of them all
#### Health
##### GPT
Formula for GPT's health `AIs[x].maxHealth = 150 * (1 + (.2 * level));`
##### Copilot & Gemini
Copilot and Gemini share same formula for health `AIs[x].maxHealth = 250 * (1 + (.1 * level));`
#### Dodging
Dodging is automatic (there is chance in every normal attack that you will dodge it)
##### GPT
25% Chance
##### Copilot & Gemini
50% Chance

## Thats all i hope that you will enjoy my game