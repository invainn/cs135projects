var canvas = document.getElementById("map");
var ctx = canvas.getContext("2d");

var baseImage = new Image();
baseImage.src = "assets/base.png";

var baseX = 320;
var baseY = 430;

var speedy1 = new Image();
speedy1.src = "assets/speedy.png";

var speedy2 = new Image();
speedy2.src = "assets/speedy.png";

var speedy3 = new Image();
speedy3.src = "assets/speedy.png";

var speedyX1 = 320;
var speedyY1 = 60;

var speedyX2 = 320;
var speedyY2 = 10;

var speedyX3 = 320;
var speedyY3 = 110;

var bubbleX = 240;
var bubbleY = 320;

var speed = 5;
var direction = 1;
var dt = 1000/30.0;

var speedySpeed1 = Math.random() * 10;
var speedySpeed2 = Math.random() * 10;
var speedySpeed3 = Math.random() * 10;

var speedyDirection1 = 1;
var speedyDirection2 = 1;
var speedyDirection3 = 1;

var bubbles1 = new Image();
bubbles1.src = "assets/bubbleSmall.png";
bubbles1.addEventListener("load", drawImage);

var bubbles2 = new Image();
bubbles2.src = "assets/bubbleSmall.png";
bubbles2.addEventListener("load", drawImage);

var bubbles3 = new Image();
bubbles3.src = "assets/bubbleSmall.png";
bubbles3.addEventListener("load", drawImage);

var bubbleX1 = baseX;
var bubbleY1 = 430;

var bubbleX2 = baseX;
var bubbleY2 = baseY;

var bubbleX3 = baseX;
var bubbleY3 = baseY;

var bubbleSpeed1 = 0;
var bubbleSpeed2 = 0;
var bubbleSpeed3 = 0;

var shot = 0;

function drawImage() {
	setInterval(update, 1000/25.0);
}

function update() {
	ctx.clearRect(0, 0, 640, 480);


	ctx.drawImage(baseImage, baseX, baseY);

	ctx.drawImage(bubbles1, bubbleX1, bubbleY1);
	ctx.drawImage(bubbles2, bubbleX2, bubbleY2);
	ctx.drawImage(bubbles3, bubbleX3, bubbleY3);

	ctx.drawImage(speedy1, speedyX1, speedyY1);
	ctx.drawImage(speedy2, speedyX2, speedyY2);
	ctx.drawImage(speedy3, speedyX3, speedyY3);

	baseX += speed * direction;

	bubbleX1 += speed * direction;
	bubbleX2 += speed * direction;
	bubbleX3 += speed * direction;

	bubbleY1 -= bubbleSpeed1;
	bubbleY2 += bubbleSpeed2;
	bubbleY3 += bubbleSpeed3;


	speedySpeed = Math.random() * 10;
	speedyX1 += speedySpeed1;

	speedySpeed = Math.random() * 10;
	speedyX2 += speedySpeed2;

	speedySpeed = Math.random() * 10;
	speedyX3 += speedySpeed3;

	if (baseX > canvas.width - baseImage.width || baseX < 0) {
		direction = -direction;
	}

	if (speedyX1 > canvas.width - speedy1.width || speedyX1 < 0) {
		speedyDirection1 = -speedyDirection1;
		speedySpeed1 = Math.random() * 10 * speedyDirection1;
	}

	if (speedyX2 > canvas.width - speedy2.width || speedyX2 < 0) {
		speedyDirection2 = -speedyDirection2;
		speedySpeed2 = Math.random() * 10 * speedyDirection2;
	}

	if (speedyX3 > canvas.width - speedy3.width || speedyX3 < 0) {
		speedyDirection3 = -speedyDirection3;
		speedySpeed3 = Math.random() * 10 * speedyDirection3;
	}

}

document.body.onkeypress = function(e) {
	if(e.keyCode == 39) {
		if(direction < 0) {
			direction = -direction;
			update();
		}
	}
	if(e.keyCode == 32) {
		if(direction > 0) {
			direction = -direction;
			update();
		}
	}
	//if(e.keyCode == 32) {
	//	bubbleSpeed1 = 5;
	//	update();
	//}
}


console.log("complete");