# AK Event-Driven Architecture
## Overview
The Event-Driven pattern plays a central role in the application, handling all events that occur during runtime. It allows multiple tasks to run cooperatively without blocking the system. As a result, the game remains responsive while an OTA update is running
## Components
The pattern is composed of several components that work together to provide an efficient and flexible execution. Each component has a specific responsibility within the architecture
| Component | Description |
|----------|-------------|
| **Task** | Handles incoming events |
| **Message** | Contains task data |
| **Message Pool** | Stores pre-allocated messages |
| **Priority Queue** | Stores messages grouped by priority |
| **Scheduler** | Gets and dispatches messages to task handlers |
## Event Execution Flow
