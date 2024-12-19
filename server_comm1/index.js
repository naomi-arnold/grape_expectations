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

function sendMessage(e) {
  e.preventDefault();
  if (!websocketConnection) {
    alert("Cannot send message, WebSocket connection is not active.")
  }
  websocketConnection.send(document.getElementById("send-message-input").value)

}

document.addEventListener("DOMContentLoaded", function () {
  document.getElementById("connect-form").addEventListener("submit", connectToServer);
  document.getElementById("send-message-form").addEventListener("submit", sendMessage);
});