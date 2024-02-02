document.addEventListener('DOMContentLoaded', (event) => {
    const sidebar = document.getElementById('sidebar');
    const toggleButton = document.getElementById('toggleSidebar');
  
    toggleButton.addEventListener('click', function() {
      sidebar.classList.toggle('sidebar-expanded');
    });
  
    // ... (resto del JavaScript) ...
  
    const modeSwitch = document.getElementById('modeSwitch');
    const modeLabel = document.getElementById('modeLabel');
    const body = document.body;
  
    modeSwitch.addEventListener('change', function() {
      if (this.checked) {
        body.classList.add('light-mode');
        modeLabel.textContent = 'Light Mode';
      } else {
        body.classList.remove('light-mode');
        modeLabel.textContent = 'Dark Mode';
      }
    });
  
    // ... (altro codice) ...
  });