let board = [" ", " ", " ", " ", " ", " ", " ", " ", " "];
let turn = 1;
let gameOver = false;

const boardDiv = document.getElementById("board");
const statusText = document.getElementById("status");
const resetBtn = document.getElementById("resetBtn");

const wins = [
  [0,1,2],[3,4,5],[6,7,8],
  [0,3,6],[1,4,7],[2,5,8],
  [0,4,8],[2,4,6]
];

function drawBoard() {
  boardDiv.innerHTML = "";
  for (let i = 0; i < 9; i++) {
    const btn = document.createElement("button");
    btn.className = "cell";
    btn.textContent = board[i] === " " ? "" : board[i];
    btn.disabled = gameOver || board[i] !== " ";
    btn.addEventListener("click", () => playMove(i));
    boardDiv.appendChild(btn);
  }
}

function checkWin(c) {
  return wins.some(line => line.every(i => board[i] === c));
}

function playMove(i) {
  if (gameOver || board[i] !== " ") return;

  const player = (turn % 2 === 1) ? "X" : "O";
  board[i] = player;

  if (checkWin(player)) {
    statusText.textContent = `Player ${player} wins!`;
    gameOver = true;
  } else if (turn === 9) {
    statusText.textContent = "Draw!";
    gameOver = true;
  } else {
    turn++;
    statusText.textContent = `Player ${(turn % 2 === 1) ? "X" : "O"}'s turn`;
  }

  drawBoard();
}

function resetGame() {
  board = [" ", " ", " ", " ", " ", " ", " ", " ", " "];
  turn = 1;
  gameOver = false;
  statusText.textContent = "Player X's turn";
  drawBoard();
}

resetBtn.addEventListener("click", resetGame);
drawBoard();

