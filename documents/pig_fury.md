# Pig Fury Documentation
## Introduction

## Table of Objects

| Object | Go |
|:-------|:--:|
| **Character** | <a href="#Character">Jump to section</a> |
| **Weapon** | <a href="#Weapon">Jump to section</a> |
| **Gameplay** | <a href="#Gameplay">Jump to section</a> |
| **Menu** | <a href="#Menu">Jump to section</a> |
| **Configuration** | <a href="#Configuration">Jump to section</a> |
| **Sound** | <a href="#Sound">Jump to section</a> |

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

### State Machine
The diagram below describes how the state changes when the player presses the mode button
<img width="60%" alt="fsm_jump" src="https://github.com/user-attachments/assets/951b893b-e9d8-453c-beab-3f7cb02b02bb" />

### Attack State Machine
The diagram below describes how the attack state changes when the player presses the attack button
<img width="60%" alt="pig_atk_fsm" src="https://github.com/user-attachments/assets/268c80de-5122-4d04-96b0-1498e219d7a0" />

### Init Flow Chart
When the gameplay starts, the Pig is created with many attributes. Some attributes depend on the game mode, such as hp
<img width="20%" alt="pig_init" src="https://github.com/user-attachments/assets/03cb02cc-24f8-4b2a-85dd-d3ace3b95c2a" />

### Input Flow Chart
When the player presses a button, all the things the game does are just changing the state. This flow below will describe how it works
<img width="80%" alt="input_pf_pug" src="https://github.com/user-attachments/assets/266f6d48-d045-473a-8eff-cc881fdb0cbd" />

### Update Flow Chart

### Render Flow Chart

<a id="Weapon"></a>
## 2. Weapon

<a id="Gameplay"></a>
## 3. Gameplay

<a id="Menu">

## 4. Menu

<a id="Configuration"></a>
## 5. Configuration

<a id="Sound"></a>
## 6. Sound
