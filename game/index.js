const { app, BrowserWindow } = require('electron');
const path = require('path');

// Add debugging to help us understand what's happening
const fs = require('fs');

let mainWindow;

function createWindow() {
    // Log the current directory and file paths
    console.log('Current directory:', __dirname);
    const htmlPath = path.join(__dirname, 'src', 'renderer', 'index.html');
    console.log('Looking for HTML file at:', htmlPath);
    
    // Check if the file exists
    console.log('HTML file exists:', fs.existsSync(htmlPath));

    mainWindow = new BrowserWindow({
        width: 1200,
        height: 800,
        webPreferences: {
            contextIsolation: true,
            nodeIntegration: false,
            preload: path.join(__dirname, 'src', 'preload.js')
        }
    });

    // Add error handling for file loading
    try {
        mainWindow.loadFile(htmlPath);
        
        // Open DevTools to help with debugging
        mainWindow.webContents.openDevTools();
        
        // Log any load errors
        mainWindow.webContents.on('did-fail-load', (event, errorCode, errorDescription) => {
            console.error('Failed to load:', errorCode, errorDescription);
        });
    } catch (error) {
        console.error('Error loading file:', error);
    }
}

app.whenReady().then(createWindow);

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) {
        createWindow();
    }
});