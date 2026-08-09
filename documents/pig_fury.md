# Pig Fury Documentation
## Introduction

## Table of Objects

| Object | Go |
|:-------|:--:|
| **Character** | <a href="#Character">Jump to section</a> |
| **Weapon** | <a href="#Weapon">Jump to section</a> |
| **Gameplay** | <a href="#Gameplay">Jump to section</a> |

<a id="Character"></a>
## 1. Character
At this moment, there are 2 characters in this game: Pig (player) and Wolf (enemy). Following the OOP design, I create a base class, and Pig and Wolf extend it
## 1.1. Class Hierarchy
<img width="50%" alt="Class_Hierarchy" src="https://github.com/user-attachments/assets/0e9a3e58-c0f5-4ac6-8418-4e45270a11b2" />

## 1.2 Character Base Class
This is a base class, which has all of the attributes and behaviors that characters always have
### Class diagram
<img width="60%" alt="char_class_dia" src="https://github.com/user-attachments/assets/4f1076ee-663d-4211-b02c-f715b33939c3" />

## 1.3 Pig Character
The Pig is the player character, which extends the base class and implements its own movement, attack, and weapon behaviors
### Class diagram
<img width="60%" alt="pig_class_dia" src="https://github.com/user-attachments/assets/a2186cf2-9d9a-43d3-9b42-7a578ee5d8d9" />

### Pig State Machine
The diagram below describes how the state changes when the player presses the mode button
<img width="60%" alt="fsm_jump" src="https://github.com/user-attachments/assets/951b893b-e9d8-453c-beab-3f7cb02b02bb" />

### Pig Attack State Machine
The diagram below describes how the attack state changes when the player presses the attack button
<img width="60%" alt="pig_atk_fsm" src="https://github.com/user-attachments/assets/268c80de-5122-4d04-96b0-1498e219d7a0" />

### Pig Init Flow Chart
When the gameplay starts, the Pig is created with many attributes. Some attributes depend on the game mode, such as hp
<img width="20%" alt="pig_init" src="https://github.com/user-attachments/assets/03cb02cc-24f8-4b2a-85dd-d3ace3b95c2a" />

### Pig Input Flow Chart
When the player presses a button, all the things the game does are just changing the state. This flow below will describe how it works
<img width="80%" alt="pig_input_flow" src="https://github.com/user-attachments/assets/f2aa6aa1-3a46-4ed5-9718-0556bff84364" />

### Pig Update Flow Chart
The game updates the Pig at 60 ms intervals. The main activity during the update is to count down the tick and change the state to NONE when the tick reaches limit

<img width="80%" alt="pig_update_flow" src="https://github.com/user-attachments/assets/bb42fda5-08de-4dde-b0f8-0e66c367a37b" />

### PIG Render Flow Chart

<img width="80%" alt="pig_flow_render" src="https://github.com/user-attachments/assets/0d4f287f-797e-4198-8036-92f6b83428b3" />

## 1.4 Enemy Character
When I create the enemy for this game, I want to make a structure that can add more enemies but without changing any existing code. Therefore I create an enemy manager and several pools for different enemy types. The game randomly selects enemies and puts them into a common pool for spawning during gameplay
</br>
Note: At this moment, I have only made one enemy type. I will update it more if I have more time

### Enemy Manager Class diagram
<img width="60%" alt="ene_mng_class" src="https://github.com/user-attachments/assets/91d6972b-f0df-480f-9a4f-5c5bebaba27a" />

### Spawm Enemy Flow
<img width="20%" alt="spawm_enemy_flow" src="https://github.com/user-attachments/assets/b21ec4c9-902a-4890-b2d4-026987f636e6" />

### Wolf Basic Character
Wolf Basic is the first enemy type implemented in the game. It extends the pf_char base class and implements its own behavior and state
### Wolf Class diagram
<img width="60%"  alt="wolf_basic_class" src="https://github.com/user-attachments/assets/24e382ab-ad82-4d58-8bd9-486fc8601b72" />

### Wolf State Machine
<img width="60%" alt="wolf_fsm" src="https://github.com/user-attachments/assets/1d4ec325-4fd1-4fe6-819a-3ff422a34e35" />

### Wolf Update Flow Chart
The wolf will change state after the conditions are reached. This flow shows how the wolf state changes
<img width="80%" alt="wolf_update_flow" src="https://github.com/user-attachments/assets/65aea94f-8ec5-492f-b326-267739ba5c6e" />

### Wolf Render Flow Chart
<img width="80%"  alt="wolf_render_flow" src="https://github.com/user-attachments/assets/7bb0cb43-5ee9-45ea-91ac-e918f62e5751" />


<a id="Weapon"></a>
## 2. Weapon
As the enemy, the weapon also has a similar structure. The main difference is that the weapon always spawns with the enemy
### Weapon Manager Class diagram  
<img width="60%" alt="weapon_class_dia" src="https://github.com/user-attachments/assets/1eaaa250-9aff-49ae-b1a0-b6046ce65b78" />

### Axe Class diagram
<img width="40%" alt="axe_class" src="https://github.com/user-attachments/assets/d75ad0ff-fc4a-45db-9440-35736b7925d9" />

### Axe State Machine

<img width="60%"  alt="axe_fsm" src="https://github.com/user-attachments/assets/5733785b-d20c-4308-890e-316199d7e2d6" />


<a id="Gameplay"></a>
## 3. Gameplay

