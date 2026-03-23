;LAB 8 - Homework

;ex1

	;ex1.1

;method without function
(setq a 19)
(setq b 22)
(+ 22 (* a (+ 13 b)))
;result 687

;method with function
(defun ex1.1 ()
  (setq a 19)
  (setq b 22)
  (setq res (+ 22 (* a (+ 13 b))))
)
;result 687

	;ex1.2

;method without function\
(setq a 2)
(setq b 2)
(setq c 2)
(setq d 2)
(+ (* a b) (* c d))
;result 8

;method with function
(defun ex1.2 ()
  (setq a 2)
  (setq b 2)
  (setq c 2)
  (setq d 2)
  (setq res (+ (* a b) (* c d)))
)
;resutl 8

;ex2

(defun deg2rad (deg / rad)
  (setq rad(float (* deg(/ pi 180))))
  (princ (strcat "Rad = " (rtos rad)))
  (princ)
)

(defun rad2deg (rad / deg)
  (setq deg(fix (* rad(/ 180 pi))))
  (princ (strcat "Deg = " (itoa deg)))
  (princ)
)