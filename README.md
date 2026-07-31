# Pig Fury Game built on AK Embedded Base Kit

<img width="100%" alt="Background" src="https://github.com/user-attachments/assets/57050db9-2eda-402c-9fb3-1daa90e4cbce" />

## Gameplay Demonstration


## Table of Contents
| Content | Go |
|---------|:--:|
| Quick Start | <a href="#quick-start">Jump to section</a> |
| Software Architecture | <a href="#software-architecture">Jump to section</a> |
| Task Processing Flow | <a href="#task-process-flow">Jump to section</a> |
| AK Pig Fury Game | <a href="#gameplay">Jump to section</a> |

<a id="software-architecture"></a>
## Software Architecture
The firmware is divided into three partitions:

- **Bootloader** [`0x08000000`]: System startup and firmware update
- **Shared Data** [`0x08002000`]: Data shared between the boot and app
- **Application** [`0x08003000`]: Main application

<img width="50%" alt="SW_Arch6" src="https://github.com/user-attachments/assets/68f97193-24ef-442e-a5a1-3fa1633e3013" />


<a id="task-process-flow"></a>
## Task Processing Flow
Application tasks are processed using two mechanisms: one handles incoming events (Event-Driven), while the other executes continuously in every main loop iteration (Polling)
### Event-Driven Task

### Polling Task

<a id="gameplay"></a>
## AK Pig Fury Game
