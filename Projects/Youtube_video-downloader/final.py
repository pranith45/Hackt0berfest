import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QGroupBox, QVBoxLayout, QGroupBox, QHBoxLayout, QDialog,QLineEdit,QWidget,QFormLayout,QLabel,QProgressBar
from PyQt5 import QtGui
from PyQt5.QtCore import QRect
from PyQt5 import QtCore
from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt

from pytube import YouTube, Playlist


# inherit from class QMainwindow
link="banseedhar"
class Window(QMainWindow):
    def __init__(self):
        super().__init__()
        
        self.title = "Yotube Video Downloder"
        self.top = 200
        self.left = 200
        self.width = 1000
        self.height = 500
        
        self.progressBar = QProgressBar(self) 
        self.progressBar.setGeometry(250,300, 500, 20)
        

        self.initwindow()
        self._button()
        self.show()

    def initwindow(self):
        
        self.setWindowIcon(QtGui.QIcon("C:/Users/banseedhar/Desktop/work/Python-script/youtube.png"))
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        self.nameLabel = QLabel(self)
        self.nameLabel.setText('Link:')
        self.nameLabel.setStyleSheet('QLabel { font:15px;font-weight:bold}')
        self.line = QLineEdit(self)
        self.line.setToolTip("<h4>paste link for download video from youtube</h4>")
        self.line.move(138, 20)
        self.line.resize(700,32)
        self.nameLabel.move(100, 20)
        
    def downloadCallback(self,stream, chunk, bytes_remaining):
        fileSize = stream.filesize
        bytes_downloaded = fileSize - bytes_remaining
        percentage = round((bytes_downloaded / fileSize) * 100, 2)
        print(f"{percentage}% Downloaded", end="\r") 

        if fileSize > 0: 
            percentage =(round((bytes_downloaded / fileSize) * 100, 2))
            self.progressBar.setValue(percentage) 
            QApplication.processEvents() 
        

    def clickme_v_o(self):
        link=self.line.text()
        yt=YouTube(link,on_progress_callback=self.downloadCallback)
        yt.streams.filter(progressive=True).order_by('resolution').first().download()
        self.label1 = QLabel(self)
        self.label1.setText('your video is downloaded successfully.......')
        self.label1.setStyleSheet('QLabel { font:15px;font-weight:bold}')
        self.label1.move(250,330)
        self.label1.resize(400,20)
        self.label1.show()

        
    def clickme_o(self):
        link=self.line.text()
        yt=YouTube(link,on_progress_callback=self.downloadCallback)
        yt.streams.filter(only_audio=True).first().download()
        self.label2 = QLabel(self)
        self.label2.setText('your audio is downloaded successfully........')
        self.label2.setStyleSheet('QLabel { font:15px;font-weight:bold}')
        self.label2.move(250,330)
        self.label2.resize(400,20)
        self.label2.show()


    def _button(self):
        button = QPushButton("Download video",self)
        button.setIcon(QtGui.QIcon("C:/Users/banseedhar/Desktop/work/Python-script/audio+video.jpg"))
        button.setGeometry(QRect(100,100,300,100))
        button.setToolTip("<h4>click for download video</h4>")
        button.clicked.connect(self.clickme_v_o)
        button.setIconSize(QtCore.QSize(40,40))
        button.setStyleSheet('QPushButton {background-color: #A3C1DA;font:15px;border-radius:4px;font-weight:bold;}')

        button2=QPushButton("Download Audio",self)
        button2.setIcon(QtGui.QIcon("C:/Users/banseedhar/Desktop/work/Python-script/audio.jpg"))
        button2.setGeometry(QRect(500,100,300,100))
        button2.setToolTip("<h4>click for download audio</h4>")
        button2.clicked.connect(self.clickme_o)
        button2.setMinimumHeight(40)
        button2.setIconSize(QtCore.QSize(40,40)) 
        button2.setStyleSheet('QPushButton {background-color: #A3C1DA;font:15px;border-radius:4px;font-weight:bold}')


app=QApplication(sys.argv)
window=Window()
sys.exit(app.exec())        

