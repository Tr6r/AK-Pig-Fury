# AK Event-Driven Architecture
## Overview
The Event-Driven pattern plays a central role in the application, handling all events that occur during runtime. It allows multiple tasks to run cooperatively without blocking the system. As a result, the game remains responsive while an OTA update is running
## Components
The pattern is composed of several components that work together to provide an efficient and flexible execution. Each component has a specific responsibility within the architecture
| Component | Description |
|----------|-------------|
| **Task** | Handles incoming events |
| **Message** | Contains task data |
| **Signal** | Task know how to handle this message |
| **Message Pool** | Stores pre-allocated messages |
| **Priority Queue** | Stores messages grouped by priority |
| **Scheduler** | Gets and dispatches messages to task handlers |
## Event Execution Flow
The following diagrams illustrate how an event flows through the pattern, from event generation to task execution.
#### Event Generation and Message Posting
When an event occurs, a message is taken from the message pool, filled with the event information, and posted to the priority queue.
<img width="80%" alt="event_gen_and_post" src="https://github.com/user-attachments/assets/e94161c2-e0f4-43a4-b1d2-33ee68e88c0c" />

#### Task Scheduling
The scheduler continuously checks the priority queues, selects the next message to be processed, and dispatches it to the task handler.
<img width="80%" alt="task_scheduler" src="https://github.com/user-attachments/assets/1986234e-3355-4dc2-bfbc-9b222cbb6924" />

#### Task Execution
After receiving a message, the task handler processes it based on the message signal. When the execution is complete, the message is returned to the message pool.
<img width="80%" alt="task_handler" src="https://github.com/user-attachments/assets/4938008d-4957-4a5f-adee-6aafec01f54a" />

