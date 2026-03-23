(defun C:ZW ()
  (command "ZOOM" "Window" pause pause)
  (princ)
)

(defun findx ()
  (* x 1)
)

(defun setx ()
  (setq x 2)
)

(defun xlocal (/ x)
  (setq x 0)
  (print x)
  (princ)
)