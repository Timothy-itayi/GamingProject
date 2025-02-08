const { contextBridge, ipcRenderer } = require('electron');
const gameEngine = require('../game-engine/build/Release/game_engine');

// Expose protected methods that allow the renderer process to use
// the game engine through a secure bridge
contextBridge.exposeInMainWorld(
    'gameAPI', {
        initialize: () => gameEngine.initialize(),
        getGameState: () => gameEngine.getGameState(),
        makeChoice: (choiceId) => gameEngine.makeChoice(choiceId),
        saveGame: () => gameEngine.saveGame(),
        loadGame: () => gameEngine.loadGame()
    }
);