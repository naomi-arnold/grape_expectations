let websocketConnection = undefined;
let messageQueue = ["", "", "", "", ""];

async function connectToServer(e) {
  // Prevent page from reloading
  e.preventDefault();
  websocketConnection = await new WebSocket("ws://34.28.153.91");
  console.log(websocketConnection);
  websocketConnection.addEventListener("open", connectionOpen);
  websocketConnection.addEventListener("close", connectionClosed);
  websocketConnection.addEventListener("message", (message) => {
    messageQueue.pop();
    messageQueue.unshift(message.data);
    console.log(messageQueue);
    renderMessages(messageQueue);
  })

}

function connectionOpen() {
  websocketConnection.send(document.getElementById("server-id").value)
  document.getElementById("connection-status").innerText = "Connected"
}

function connectionClosed() {
  websocketConnection = undefined;
  document.getElementById("connection-status").innerText = "Not Connected"
}

function renderMessages(messages) {
  messages.forEach((message, index) => {
    document.getElementById("msg-" + (index + 1)).innerText = message;
  });
}

function sendMessage(e, direction) {
  e.preventDefault();
  if (!websocketConnection) {
    alert("Cannot send message, WebSocket connection is not active.")
  }
  // Send the message based on the button clicked
  websocketConnection.send(direction);

}

document.addEventListener("DOMContentLoaded", function () {
  document.getElementById("connect-form").addEventListener("submit", connectToServer);
  
  // Attach event listeners for the arrow buttons
  document.getElementById("upBtn").addEventListener("click", function (e) {
    sendMessage(e, "forward");
  });
  
  document.getElementById("downBtn").addEventListener("click", function (e) {
    sendMessage(e, "backward");
  });
  document.getElementById("leftBtn").addEventListener("click", function (e) {
    sendMessage(e, "left");
  });
  
  document.getElementById("rightBtn").addEventListener("click", function (e) {
    sendMessage(e, "right");
  });

  document.getElementById("rotateCwBtn").addEventListener("click", function (e) {
    sendMessage(e, "cw");
  });
  
  document.getElementById("rotateCcwBtn").addEventListener("click", function (e) {
    sendMessage(e, "ccw");
  });

  document.getElementById("stopBtn").addEventListener("click", function (e) {
    sendMessage(e, "stop");
  });
  // mousedown
  // document.addEventListener("mouseup" , sendMessage(e, "stop"));

});


