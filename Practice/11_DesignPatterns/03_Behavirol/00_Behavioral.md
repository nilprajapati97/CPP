-: 🔹 Behavioral Patterns 🔹
Improve or enable interaction and communication between objects.

✅ Observer — Publish/Subscribe notifications to multiple dependents.
✅ Strategy — Select algorithm’s behavior at runtime.
✅ Command — Encapsulate requests as object (for queuing, logging, undo/redo).
✅ Chain of Responsibility — Pass requests along a chain of handlers.
✅ Mediator — Centralize complex communications between components.
✅ Iterator — Traverse elements in a collection gracefully.
✅ Memento — Save and restore object’s state.
✅ State — Alter behavior when object’s internal state evolves.
✅ Template Method — General algorithm structure with customizable steps.
✅ Visitor — Add operations to object structures without changing their classes.



✅ Summary Table
// +===================================================
// | Pattern                | Practical Use Case                          |
// +===================================================
// | Observer              | GUI listeners, stock tickers                 |
// | Strategy              | Pluggable algorithms (sort, compression)     |
// | Command               | Undo/redo, button click commands             |
// | Chain of Resp.        | Event handling, logging filters              |
// | Mediator              | Chat systems, UI coordination                |
// | Iterator              | Looping through custom containers            |
// | Memento               | Undo systems, game state saving              |
// | State                 | Game modes, media player states              |
// | Template Method       | Game lifecycle, framework hooks              |
// | Visitor               | Tax engine, compiler AST traversal           |


| Pattern  | Intent                        | When to Use            | Real-World Analogy     | Related Patterns        |
| -------- | ----------------------------- | ---------------------- | ---------------------- | ----------------------- |
| Strategy | Select behavior at runtime    | Replace if-else chains | Payment via UPI/Credit | State, Bridge           |
| Observer | Notify many on state change   | Event/listener systems | YouTube subscriptions  | Mediator                |
| Command  | Encapsulate request as object | Undo/redo systems      | Remote Control Buttons | Memento, Chain of Resp. |
| ...      | ...                           | ...                    | ...                    | ...                     |

