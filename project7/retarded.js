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

var speed = 5;
var direction = 1;

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

var bubbleX1 = 0;
var bubbleY1 = baseY;

var bubbleX2 = 0;
var bubbleY2 = baseY;

var bubbleX3 = 0;
var bubbleY3 = baseY;

var bubbleSpeed1 = 0;
var bubbleSpeed2 = 0;
var bubbleSpeed3 = 0;

var shot1 = 0;
var shot2 = 0;
var shot3 = 0;

console.log(bubbles1.width);

function drawImage() {
	setInterval(update, 1000/30.0);
}

function update() {
	ctx.clearRect(0, 0, 640, 480);

	ctx.drawImage(baseImage, baseX, baseY);

	if(shot1 == 1) {
		if(bubbleY1 > canvas.length - bubbles1.length || bubbleY1 < 0 || intersectRect(speedy1, bubbles1) || intersectRect(speedy2, bubbles1) || intersectRect(speedy3, bubbles1)) {
			bubbleX1 = 0;
			bubbleSpeed1 = 0;
			bubbleY1 = baseY;
			shot1--;
		} else {
			ctx.drawImage(bubbles1, bubbleX1, bubbleY1);
		}
	}	

	if(shot2 == 1) {
		if(bubbleY2 > canvas.length - bubbles2.length || bubbleY2 < 0 || intersectRect(bubbles2, speedy1) || intersectRect(bubbles2, speedy2) || intersectRect(bubbles2, speedy3)) {
			bubbleX2 = 0;
			bubbleSpeed2 = 0;
			bubbleY2 = baseY;
			shot2--;
		} else {
			ctx.drawImage(bubbles2, bubbleX2, bubbleY2);
		}
	}	

	if(shot3 == 1) {
		if(bubbleY3 > canvas.length - bubbles3.length || bubbleY3 < 0 || intersectRect(bubbles3, speedy1) || intersectRect(bubbles3, speedy2) || intersectRect(bubbles3, speedy3)) {
			bubbleX3 = 0;
			bubbleSpeed3 = 0;
			bubbleY3 = baseY;
			shot3--;
		} else {
			ctx.drawImage(bubbles3, bubbleX3, bubbleY3);
		}
	}	

	if(intersectRect(speedy1, bubbles1) || intersectRect(speedy1, bubbles2) || intersectRect(speedy1, bubbles3)) {
		ctx.drawImage(speedy1, speedyX1, speedyY1);
	}

	if(intersectRect(speedy2, bubbles1) || intersectRect(speedy2, bubbles2) || intersectRect(speedy2, bubbles3)) {
		ctx.drawImage(speedy2, speedyX2, speedyY2);
	}

	if(intersectRect(speedy3, bubbles1) || intersectRect(speedy3, bubbles2) || intersectRect(speedy3, bubbles3)) {
		ctx.drawImage(speedy3, speedyX3, speedyY3);
	}

	baseX += speed * direction;

	bubbleY1 -= bubbleSpeed1;
	bubbleY2 -= bubbleSpeed2;
	bubbleY3 -= bubbleSpeed3;


	speedySpeed = Math.random() * 7 + 3;
	speedyX1 += speedySpeed1;

	speedySpeed = Math.random() * 7 + 3;
	speedyX2 += speedySpeed2;

	speedySpeed = Math.random() * 7 + 3;
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

function intersectRect(r1, r2) {
	return !(r2.left > r1.right || 
		     r2.right < r1.left || 
		     r2.top > r1.bottom || 
		     r2.bottom < r1.top);
}

document.body.onkeydown = function(e) {
	if(e.keyCode == 39) {
		if(direction < 0) {
			direction = -direction;
			update();
		}
	}
	if(e.keyCode == 37) {
		if(direction > 0) {
			direction = -direction;
			update();
		}
	}
	if(e.keyCode == 32) {
		if(shot1 == 0) {
			bubbleX1 = baseX;
			bubbleSpeed1 = 5;
			shot1++;
		} else if(shot2 == 0) {
			bubbleX2 = baseX;
			bubbleSpeed2 = 5;
			shot2++;
		} else if(shot3 == 0) {
			bubbleX3 = baseX;
			bubbleSpeed3 = 5;
			shot3++;
		} 
		update();
	}
}


console.log("complete");