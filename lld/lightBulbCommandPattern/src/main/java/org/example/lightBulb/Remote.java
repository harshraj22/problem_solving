package org.example.lightBulb;

import java.util.Stack;

public class Remote {
    Stack<Command> commands = new Stack<>();

    public void addCommand(Command command) {
        this.commands.add(command);
    }

    public void pressButton() {
        this.commands.getFirst().execute();
    }

    public void pressUndo() {
        this.commands.getFirst().undo();
    }

    public void pressRedo() {
        this.commands.getFirst().redo();
    }
}
