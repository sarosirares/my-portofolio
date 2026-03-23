(defun projdist (p0 p1)
	(list (abs (- (car p0) (car p1))) ; dX = |x0 - x1|
	      (abs (- (cadr p0) (cadr p1))) ; dY = |y0 - y1|
	)
)

(defun insidew (cor0 cor1 pt)
  (and (<= (car cor0) (car pt) (car cor1))
       (<= (cadr cor0) (cadr pt) (cadr cor1))
  )
)


(defun C:CIRCLEC ( / c cr0 cr1)
  (setq cr0 (getpoint "\nChoose the first corner of the rectangular box:"))
  (setq cr1 (getcorner cr0 "\nChoose the second corner of the rectangular box:"))

  (command "RECTANG" cr0 cr1)
  
  (setq c (getpoint "\nChoose center point for circle inside of the box:"))
  (while (not (insidew cr0 cr1 c))
  	  (setq c (getpoint "\nCenter is not in the box. Choose center point for circle inside of the box:"))
  )
  
  (setq rad (getreal "\nChoose circle radius that fits the box:"))
  (while (> rad (min(apply 'min(projdist c cr0))(apply 'min(projdist c cr1))))
  	  (setq rad (getreal "\nChoose circle radius that fits the box:"))
  )

  (command "CIRCLE" c rad)

  (command "ERASE" cr0 "")

)