# Minesweeper
Trò chơi Dò mìn 
Trần Ngọc Hoàn
Thời gian hoàn thành : 11/5/2018

Dò mìn hay Gỡ mìn (tiếng Anh: Minesweeper) là một trò chơi trên máy tính dành cho một người chơi. Trò chơi được xây dựng như một chương trình giải trí cài đặt trên hệ điều hành Microsoft Windows .

Mô tả trò chơi và cách chơi:
- Người chơi khởi đầu với một bảng ô vuông trống thể hiện "bãi mìn".
- Kích  vào một ô vuông trong bảng. Nếu không may trúng phải ô có mìn thì cuộc chơi coi như kết thúc. Nếu ô đó không có mìn và một vùng các ô sẽ được mở ra cùng với những con số. Số trên một ô là chỉ số ô có mìn trong cả thảy 8 ô nằm lân cận với ô đó.
- Nếu chắc chắn một ô có mìn, hãy đánh dấu vào ô đó bằng hình lá cờ
-Trò chơi kết thúc khi tất cả các ô ko phải mìn được mở ra


Hướng phát triển trò chơi trong tương lai (để trò chơi hoàn thiện hơn):
-Thêm các ô quà tặng với tính năng: 
     +mở random 1 ô bất kì,
     +thêm lượt chơi, tăng điểm,
     +mở số x mìn trên sân,
     +...
- Phát triển chơi 2(hoặc nhóm)  player: từng player mở ô, player mở phải mìn sẽ bị loại khỏi cuộc chơi, người dành chiến thắng là người sống sót cuối cùng.
-....

Mô tả Source Code:
+Common_f class: thuộc tính chung
+Main: setup Window ,Menu
click Play->CLass GamePlay();
+GamePlay(){
  play():thực hiện trò chơi	
  setup():load sprite, khởi tạo mang 2 chiều(bom,số bom xung quang,...)
  win ():khi thắng cuộc draw YouWin;
  stop():click phải bom, mở toàn bộ các ô.
}

+Node:(Đối tượng Ô) {
  -Sprite trên:
  -Sprite dưới:
  -Tỏa độ
  -Đã lât?
  -Gắn cờ ?
  -Kinds:các loại}

