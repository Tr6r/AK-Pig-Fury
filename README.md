# AK Pig Fury Game built on AK Embedded Base Kit

<img width="100%" alt="game_bamner" src="https://github.com/user-attachments/assets/4ece8dd3-af9d-4872-874c-de82743ecd25" />

## Gameplay Demonstration
<div align="center">

https://github.com/user-attachments/assets/e14b3253-f0c7-4ac7-9933-ed420052c427

<div/>
<div align="left">
<div/>

## Table of Contents
| Content | Go |
|---------|:--:|
| Introduction | <a href="#introduction">Jump to section</a> |
| Game Overall | <a href="#game_overall">Jump to section</a> |
| Game Screens | <a href="#game_scr">Jump to section</a> |
| Game Objects| <a href="#game_ob">Jump to section</a> |
| Game Flow | <a href="#game_flow">Jump to section</a> |
| Getting Started | <a href="#getting_started">Jump to section</a> |

<a id="game_overall"></a>
## Introduction
Hi guys, welcome to my project. This is a game built on the STM32 platform, following an event-driven pattern. The game was designed with a product-oriented engineering approach, focusing on:
 - Modular architecture
 - Clear object relationships
 - An extensible design that allows new features to be added without complexity

<a id="game_overall"></a>
## Game Overall
The game is inspired by Iron Snout, a popular fighting game released many years ago. Players must carefully time their attacks to avoid enemy hits and achieve the highest score possible

<a id="game_scr"></a>
## Game Screens
### Welcome screen
Displays the game name and welcomes the player before entering the main menu
<div align="center" style="display: flex; flex-direction: column;">

<img width="60%"  alt="welcome-scr" src="https://github.com/user-attachments/assets/978866fc-5613-4e26-bbb1-35415a079ae7" />

<div><b>Figure 1: Welcome Screen</b></div>

</div>

### Menu Screen
There are two options in the menu:
- Gameplay – choose to start the game
- Game Configuration – choose to set the game mode and sound

Each menu option has a dynamic icon to make the menu more lively

<div align="center" style="display: flex; flex-direction: column;">

<img width="60%"  alt="gameplay-option" src="https://github.com/user-attachments/assets/3e60b9a3-1d2f-4d99-8b14-2fb2afc73fe0" />
 
<div><b>Figure 2: Gameplay option</b>b</div>

</br>
<img width="60%"  alt="configurate-option"src="https://github.com/user-attachments/assets/92d329e1-1470-4376-a187-7646ee79c6eb" />

<div><b>Figure 3: Configuration Option</b></div>

</div>

### Gameplay Screen
The screen where the player will have to attack enemies to avoid getting a game over

**How to Play**
- Control the pig to fight incoming wolves
- Pick up the enemy's weapon to attack

**Controls**
- Button Down: attack left
- Button Up: attack right
- Button Mode: jump
 
<div align="center" style="display: flex; flex-direction: column;">

<img width="60%" alt="gameplay-scr" src="https://github.com/user-attachments/assets/7573d009-005d-4d78-9a47-9f03f202c2bc" />

<div><b>Figure 4: Gameplay Screen</b></div>

</div>

### Game Over Screen
When the pig runs out of HP, this screen will appear and show the number of enemies you have killed

<div align="center" style="display: flex; flex-direction: column;">

<img width="60%" alt="game-over-scr" src="https://github.com/user-attachments/assets/7e387277-c796-4f71-b8f2-004a2b360663" />

<div><b>Figure 5: Game Over Screen</b></div>

</div>

### Configuration Screens

The player can set the game mode and game sound:
- game mode: normal or hard
- game sound: on or off

<div align="center" style="display: flex; flex-direction: column;">

<img  width="60%" alt="configuration-scr" src="https://github.com/user-attachments/assets/e296b33a-f1cf-4599-ae61-e53d74ba48f1" />

<div><b>Figure 6: Configuration Screen</b></div>

</div>

<a id="game_ob"></a>
## Game Objects

| Game Object | Anim | Description |
|:-----------:|:-------:|:-----------:|
| **pf_pig** | <img width="90" height="135" alt="pf_pig" src="https://github.com/user-attachments/assets/ca174021-4606-48d8-86b3-1beeb8568de9" />| The character controlled by the player. It can attack enemies, jump and use enemy weapons |
| **pf_wolf** | <img width="90" height="135" alt="pf_wolf" src="https://github.com/user-attachments/assets/e28866f3-4907-417f-927d-7517a7c590a8" />|The Wolves are continuously spawned during gameplay and attack pig|
| **pf_axe** | <img width="90" height="60" alt="pf_axe" src="https://github.com/user-attachments/assets/72bd9038-43b2-4a57-a639-0deba697cfda" />| A throwable weapon that can be picked up and attack enemies |
| **pf_health_bar** | <img width="100" height="24" alt="pf_health" src="https://github.com/user-attachments/assets/6a565600-5138-44fc-8d7a-694673166c16" /> | Displays the player's current HP during gameplay |
| **pf_menu** | <img width="122" height="82" alt="pf_menu" src="https://github.com/user-attachments/assets/38b86283-46bd-487c-a657-11d5eea431e8" /> | Provides interface and handles navigation between menu options |
| **pf_config_item** |<img width="90" height="55" alt="pf_config_item" src="https://github.com/user-attachments/assets/e6a796fd-af91-45b1-add9-f037c8a27bd7" />| A configurable options in the settings screen |
| **pf_game_score** | <img width="80" height="36" alt="pf_game_score" src="https://github.com/user-attachments/assets/a8fd5842-b25c-46b0-8abe-94fab8726b9e" />| Displays the number of enemies killed by the player during gameplay |
| **pf_tone** | <img width="90" height="55" alt="pf_tone" src="https://github.com/user-attachments/assets/dfdf8e01-20a7-4ef2-8b59-9f29441c71e3" />| Controls the game sound setting |

<a id="game_flow"></a>
## Gameplay Flow
I wanna keep it really simple when someone first figures out how my game works. That's why the image below just shows the overall gameplay flow for all classes working together
 
<img width="80%" alt="overall_flow" src="https://github.com/user-attachments/assets/9d1a8371-0586-40d4-a2de-0eb7c4721788" />
 
Otherwise, if you want to dive deeper, <a href="https://github.com/Tr6r/AK-Pig-Fury-Standalone/blob/main/documents/pig_fury.md">here is my detailed game documentation</a>

<a id="getting_started"></a>
## Getting Started

I prepared a game binary file for a quick start. [Download Game Binary](https://github.com/Tr6r/AK-Pig-Fury-Standalone/blob/main/hardware/bin/ak-base-kit-stm32l151-pig-fury-game.bin)
 and flash it to the **AK Base Kit V3** to run the game directly on the hardware.

### Step 1: Clone the Repository
Clone the this repository to your local machine

### Step 2: Install the Toolchain and STM32Cube

Follow the [Getting Started Guide](https://epcb.vn/blogs/ak-embedded-software/ak-embedded-base-kit-stm32l151-getting-started) to install and configure the required tools

### Step 3: Build and Flash the Project

Navigate to the application directory and build and flash the project:

```bash
cd application/
make clean && make flash
