<?php session_start(); ?>
<html>

<head> 
    <meta charset="utf-8">
    <!-- Make site responsive on mobile/tablet -->
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans+JP&display=swap" rel="stylesheet">
    <title>Online Quiz System</title>
	<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css"> 
</head>
<!-- <link href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.4.1/css/bootstrap.min.css" rel="stylesheet"> -->
<?php
        if (isset($_POST['login'])) {
            if (isset($_POST['usertype']) && isset($_POST['username']) && isset($_POST['pass'])) {        require_once 'sql.php';
                $conn = mysqli_connect($host, $user, $ps, $project);if (!$conn) {
                    echo "<script>alert(\"Database error retry after some time !\")</script>";
                }
                $type = mysqli_real_escape_string($conn, $_POST['usertype']);
                $username = mysqli_real_escape_string($conn, $_POST['username']);
                $password = mysqli_real_escape_string($conn, $_POST['pass']);
                $password = crypt($password, 'azbycxdwevf');
                $sql = "select * from " . $type . " where mail='{$username}'";
                $res =   mysqli_query($conn, $sql);
                if ($res) {
                    global $dbmail, $dbpw;
                    while ($row = mysqli_fetch_array($res)) {
                        $dbpw = $row['pw'];
                        $dbmail = $row['mail'];
                        $_SESSION["name"] = $row['name'];
                        $_SESSION["type"] = $type;
                        $_SESSION["username"] = $dbmail;
                    }
                    if ($dbpw === $password) {
                        if ($type === 'student') {
                            header("location:homestud.php");
                        } elseif ($type === 'staff') {
                            header("Location: homestaff.php");
                        }
                    } elseif ($dbpw !== $password && $dbmail === $username) {
                        echo "<script>alert('password is wrong');</script>";
                    } elseif ($dbpw != $password && $dbmail != $username) {
                        echo "<script>alert('username name not found sing up');</script>";
                    }
                }
            }
        }
?>
<style>
     @media screen and (max-width: 620px) {
        input {
            height: 6vw !important;
        }

        .seluser {
            display: grid;
        }

        .sub {
            width: 20vw !important;
        }
    }

    .sub:hover
    {
        background-color:#8f6f67;
    }
    html, body {
        margin:0px !important;
        padding:0px !important;
    }
    .inp {
        box-sizing: content-box !important;
        width: 30vw;
        height: 3vw;
        border-radius: 10px;
        border: 2px solid black;
        padding-left: 2vw;
        font-weight: bolder;
        outline: none;

    }

    ::placeholder {
        font-weight: bold;
        font-family: 'Courier New', Courier, monospace;
        
    }

    label {
        font-weight: bolder;
        font-size: 1.5vw;
    }

    form {
        font-size: 1.5vw;
        margin: 0;
    }

    button:hover {
        background-color: #fff !important;
    }

    .bg {
        background-size: 100%;
        max-width:100%;
        height:auto;
    }

    a {
        color: #042A38;
    }
		.login{
			max-height: 70vh;
		}
</style>

<body style="margin-top:0;height: 100%;ouline:none;color: #042A38f !important;padding-botton:5vw;">
    <div class="bg" style="font-weight: bolder;background-image: url(https://images.creativemarket.com/0.1.0/ps/6151536/600/400/m2/fpnw/wm0/quiz-8-.jpg?1553762091&s=feca5a2cc1813d37f707e295a26e90f9&fmt=webp);background-repeat: no-repeat;padding: 0;margin: 0;background-size: cover;font-family: 'Courier New', Courier, monospace;opacity: 0.9;height: 105%; ">
        <center>
            <h1 class="w3-container" style=" margin-top:0;text-shadow: 2px 2px 5px black; color:#ffffff;text-transform: uppercase;width: auto;background:#8f6f67;padding: 1vw;font-family:'Noto Sans JP'">ONLINE
                QUIZ SYSTEM</h1>
        </center>
        <center>
            <div class="w3-card" class="login" style="box-shadow: 0 6px 10px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 gray;color: #042A38;width: 40vw;background-color:#ffffffab;border: 2px solid black;padding: 2vw;font-weight: bolder;margin-top:30px;border-radius: 10px;padding: top 15px; padding: bottom 15px; ">
                <form method="POST">
                    <div class="seluser">
                        <input type="radio" name="usertype" value="student" required>STUDENT
                        <input type="radio" name="usertype" value="staff" required>STAFF
                    </div><br>
                    <div class="signin">

                        <label for="username" style="text-transform:uppercase;">E-mail</label><br><br>
                        <input type="email" name="username" placeholder=" Email" class="inp" required>
                        <br><br>
                        <label for="password" style="text-transform: uppercase;">Password</label><br><br>
                        <input type="password" name="pass" placeholder="******" class="inp" required>
                        <br><br><br>
                        <input name="login" class="sub" type="submit" value="Login" style="height: 3vw;width: 10vw;font-family: 'Courier New', Courier, monospace;font-weight: bolder;border-radius: 10px;border: 2px solid black;"><br>

                </form><br>
                New user! <a href="signup.php">SIGN UP</a>
            </div>
            
    </div>
    </center>
    
    </div>
   
    
    <div class="footer" style=" font-family:;color: white; height: 80px; margin:0px;padding-top:10px;background-color:#343a40!important;display:flex:justify-content:center;align-items:center;">
	<div class="col-xl-4">
		<center> <p class="Covid-info" style="margin-bottom: 0;font-weight: 500; padding:0"> Quiz System   </p></center>	
	</div>
	<div class="col-xl-4" style="padding:0px; margin:0;">
		<center> <p style="margin:0;"> © Copyright HC, 2021. All rights reserved </p></center>
	</div>
</div> 
   
</body>

</html>