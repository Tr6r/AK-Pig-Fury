# Pig Fury Game built on AK Embedded Base Kit

<img width="100%" alt="Background" src="https://github.com/user-attachments/assets/57050db9-2eda-402c-9fb3-1daa90e4cbce" />

## Gameplay Demonstration


## Table of Contents
| Content | Go |
|---------|:--:|
| Quick Start | <a href="#quick-start">Jump to section</a> |
| Introduction | <a href="#introduction">Jump to section</a> |
| Software Architecture | <a href="#software-architecture">Jump to section</a> |
| Task Processing Flow | <a href="#task-process-flow">Jump to section</a> |
| AK Pig Fury Game | <a href="#gameplay">Jump to section</a> |

<a id="introduction"></a>
## Introduction
Hi guys, welcome to my project. This is a game built on the STM32 platform, following an event-driven pattern. The main goal of this course is to develop a product engineering mindset so I focused on building the game with:
 - Modular architecture
 - Clear object relationships
 - An extensible design that allows new features to be added without complexity
<a id="software-architecture"></a>
## Software Architecture
The firmware is divided into three partitions:

- **Application** [`0x08003000`]: Main application
- **Shared Data** [`0x08002000`]: Data shared between the boot and app
- **Bootloader** [`0x08000000`]: System startup and firmware update

<img width="50%" alt="SW_Arch6" src="https://github.com/user-attachments/assets/68f97193-24ef-442e-a5a1-3fa1633e3013" />


<a id="task-process-flow"></a>
## Task Processing Flow
Application tasks are processed using two mechanisms: one handles incoming events (Event-Driven), while the other executes continuously in every main loop iteration (Polling)
<img width="80%" alt="task_process_flow" src="https://github.com/user-attachments/assets/cf55e36a-6f5e-4a2c-b306-d48343141c0c" />

#### Event-Driven Task
<img width="80%" alt="event_driven_dia" src="https://github.com/user-attachments/assets/81862086-8254-45a9-8d1c-e710d9cecf76" />

</br>
For more details, see <a href="https://github.com/Tr6r/AK-Pig-Fury-Standalone/blob/main/documents/ak_event_driven.md">this section</a>.
</br>

<a id="gameplay"></a>
## AK Pig Fury Game
#### Game Overall
The game is inspired by Iron Snout, a popular fighting game released many years ago. Players must carefully time their attacks to avoid enemy hits and achieve the highest score possible.
#### Game Screens
I divided the game into multiple screens, each designed with a different purpose to provide a more engaging gameplay experience.
| Screen | Description |
|--------|-------------|
| **Start Up** | Displays the signature logo of this course |
| **Welcome** | Just a screen for introduction|
| **Menu** | Play the game or configure it |
| **Gameplay** | The violent activity appears here |
| **Configuration** | Make some settings here |
| **Game Over** | Notifies you lost and displays score |

<img width="80%" alt="ezgif com-resize" src="https://github.com/user-attachments/assets/3d8b3176-713f-49bb-adde-54e0281ed305" />

#### Game Objects

| Game Object | Preview | Description |
|:-----------:|:-------:|:-----------:|
| **pf_pig** | <img width="90" height="135" alt="pf_pig" src="https://github.com/user-attachments/assets/ca174021-4606-48d8-86b3-1beeb8568de9" />| The player |
| **pf_wolf** | <img width="90" height="135" alt="pf_wolf" src="https://github.com/user-attachments/assets/e28866f3-4907-417f-927d-7517a7c590a8" />| The enemy |
| **pf_axe** | <img width="90" height="60" alt="pf_axe" src="https://github.com/user-attachments/assets/72bd9038-43b2-4a57-a639-0deba697cfda" />| A throwable weapon|
| **pf_health_bar** | <img width="100" height="24" alt="pf_health" src="https://github.com/user-attachments/assets/6a565600-5138-44fc-8d7a-694673166c16" /> | The player's health |
| **pf_menu** | <img width="122" height="82" alt="pf_menu" src="https://github.com/user-attachments/assets/38b86283-46bd-487c-a657-11d5eea431e8" /> | The interface for navigating the game |
| **pf_config_item** |<img width="90" height="55" alt="pf_config_item" src="https://github.com/user-attachments/assets/e6a796fd-af91-45b1-add9-f037c8a27bd7" />| A configurable options in the settings screen |
| **pf_game_score** | <img width="80" height="36" alt="pf_game_score" src="https://github.com/user-attachments/assets/a8fd5842-b25c-46b0-8abe-94fab8726b9e" />| The player's kill score |
| **pf_tone** | <img width="90" height="55" alt="pf_tone" src="https://github.com/user-attachments/assets/dfdf8e01-20a7-4ef2-8b59-9f29441c71e3" />| The game soun |

#### Game Flow

