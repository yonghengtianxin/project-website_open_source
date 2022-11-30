
/*
window.onload = function () {
    setTimeout(setInterval("toggleSound()", 1),1000);
}

function setInterval() {
    var music = document.getElementById("music");//获取ID
    if (music.paused) { //判读是否播放  
        music.paused = false;
        music.play(); //没有就播放 
    }
}


function play(src, type) {
	document.getElementById("audioPay").innerHTML = "<embed id='embVoice' name='embed_" + type + "' src='" + src + "' autostart=true  hidden=true muted='muted'></embed>"
	var interTimePay = setInterval(function () {
		try {
			var embedVoice = document.getElementById('embVoice');
			if (!embedVoice) {
				document.getElementById("audioPay").innerHTML = "<embed id='embVoice' name='embed_" + type + "' src='" + src + "' autostart=true  hidden=true muted='muted'></embed>"
			}
			setTimeout(function () {
				document.getElementById("embVoice").innerHTML = ""
			}, 9000)
		} catch (e) {
			console.log("播放声音出现异常！", e);
		}
	}, 10000);
}
var src = "/audio/ZUN - 今宵は飄逸なエゴイスト (Live ver) ~ Egoistic Flowers.mp3";
var type = "type";
play()
*/