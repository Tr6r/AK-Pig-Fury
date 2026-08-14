# AK Pig Fury Game built on AK Embedded Base Kit

<img width="100%" alt="game_banner" src="https://github.com/user-attachments/assets/f2f61711-e4ee-4a70-b769-77866b060593" />

## Gameplay Demonstration
<div align="center">

https://github.com/user-attachments/assets/5e2c4728-e8e2-4118-a4af-ceafa488c9a6

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
I divided the game into multiple screens, each designed with a different purpose to provide a more engaging gameplay experience
| Screen | Description |
|--------|-------------|
| **Welcome** | Just a screen for introduction|
| **Menu** | Play the game or configure it |
| **Gameplay** | The violent activity appears here |
| **Configuration** | Make some settings here |
| **Game Over** | Notifies you lost and displays score |

<img width="80%" alt="ezgif com-resize" src="https://github.com/user-attachments/assets/3d8b3176-713f-49bb-adde-54e0281ed305" />

<a id="game_ob"></a>
## Game Objects

| Game Object | Anim | Description |
|:-----------:|:-------:|:-----------:|
| **pf_pig** | <img width="90" height="135" alt="pf_pig" src="https://github.com/user-attachments/assets/ca174021-4606-48d8-86b3-1beeb8568de9" />| The player |
| **pf_wolf** | <img width="90" height="135" alt="pf_wolf" src="https://github.com/user-attachments/assets/e28866f3-4907-417f-927d-7517a7c590a8" />| The enemy |
| **pf_axe** | <img width="90" height="60" alt="pf_axe" src="https://github.com/user-attachments/assets/72bd9038-43b2-4a57-a639-0deba697cfda" />| A throwable weapon|
| **pf_health_bar** | <img width="100" height="24" alt="pf_health" src="https://github.com/user-attachments/assets/6a565600-5138-44fc-8d7a-694673166c16" /> | The player's health |
| **pf_menu** | <img width="122" height="82" alt="pf_menu" src="https://github.com/user-attachments/assets/38b86283-46bd-487c-a657-11d5eea431e8" /> | The interface for navigating the game |
| **pf_config_item** |<img width="90" height="55" alt="pf_config_item" src="https://github.com/user-attachments/assets/e6a796fd-af91-45b1-add9-f037c8a27bd7" />| A configurable options in the settings screen |
| **pf_game_score** | <img width="80" height="36" alt="pf_game_score" src="https://github.com/user-attachments/assets/a8fd5842-b25c-46b0-8abe-94fab8726b9e" />| The player's kill score |
| **pf_tone** | <img width="90" height="55" alt="pf_tone" src="https://github.com/user-attachments/assets/dfdf8e01-20a7-4ef2-8b59-9f29441c71e3" />| The game sound |

<a id="game_flow"></a>
## Gameplay Flow
I wanna keep it really simple when someone first figures out how my game works. That's why the image below just shows the overall gameplay flow for all classes working together
 
<img width="80%" alt="overall_flow" src="https://github.com/user-attachments/assets/9d1a8371-0586-40d4-a2de-0eb7c4721788" />
 
Otherwise, if you want to dive deeper, <a href="https://github.com/Tr6r/AK-Pig-Fury-Standalone/blob/main/documents/pig_fury.md">here is my detailed game documentation</a>
