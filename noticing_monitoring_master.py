import cv2
import telepot
import datetime

master = 

TOKEN = ""

chaebot = telepot.Bot(TOKEN)

capture = cv2.VideoCapture(0)

while True:
    now = datetime.datetime.now()
    ret, frame = capture.read()
    cv2.imshow("VideoFrame", frame)

    if int(now.strftime('%S'))%5 == 0 :
        ret, my_capture = capture.read()
        cv2.imwrite('my_capture.jpg', my_capture)  # 캡쳐화면 저장

        img_color = cv2.imread('my_capture.jpg')
        img_color = cv2.resize(img_color, dsize=(500, 400), interpolation=cv2.INTER_AREA)
        img_gray = cv2.cvtColor(img_color, cv2.COLOR_BGR2GRAY)
        ret, img_binary = cv2.threshold(img_gray, 200, 255, 0)

        contours, hierachy = cv2.findContours(img_binary, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

        fire = 0
        for cnt in contours:
            x, y, w, h = cv2.boundingRect(cnt)

            if w > 50 and h > 50:
                cv2.rectangle(img_color, (x, y), (x + w, y + h), (0, 255, 0), 2)
                print((x + w) / 2, (y + h) / 2)
                fire += 1

        if fire:
            chaebot.sendMessage(master, '열점이 감지되었습니다.')

        cv2.imshow("result", img_color)
        '''
        cv2.waitKey(0)'''

    if cv2.waitKey(1) == 27 :
        cv2.destroyAllWindows()
        break

capture.release()
cv2.destroyAllWindows()
