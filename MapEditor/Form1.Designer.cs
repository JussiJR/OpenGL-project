
namespace MapEditor
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lstChunks = new System.Windows.Forms.ListBox();
            this.btnAddChunk = new System.Windows.Forms.Button();
            this.btnRemoveChunk = new System.Windows.Forms.Button();
            this.btnAddEdge = new System.Windows.Forms.Button();
            this.lstEdges = new System.Windows.Forms.ListBox();
            this.nudFloor = new System.Windows.Forms.NumericUpDown();
            this.nudRoof = new System.Windows.Forms.NumericUpDown();
            this.nudLink = new System.Windows.Forms.NumericUpDown();
            this.nudTexture = new System.Windows.Forms.NumericUpDown();
            this.nudPortal = new System.Windows.Forms.NumericUpDown();
            this.btnSaveToJson = new System.Windows.Forms.Button();
            this.btnRemoveEdge = new System.Windows.Forms.Button();
            this.cmbChunks = new System.Windows.Forms.ComboBox();
            this.labelFloor = new System.Windows.Forms.Label();
            this.labelRoof = new System.Windows.Forms.Label();
            this.labelLink = new System.Windows.Forms.Label();
            this.labelTexture = new System.Windows.Forms.Label();
            this.labelPortal = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.nudFloor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudRoof)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudLink)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudTexture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPortal)).BeginInit();
            this.SuspendLayout();
            // 
            // lstChunks
            // 
            this.lstChunks.FormattingEnabled = true;
            this.lstChunks.ItemHeight = 15;
            this.lstChunks.Location = new System.Drawing.Point(12, 12);
            this.lstChunks.Name = "lstChunks";
            this.lstChunks.Size = new System.Drawing.Size(200, 199);
            this.lstChunks.TabIndex = 0;
            this.lstChunks.SelectedIndexChanged += new System.EventHandler(this.lstChunks_SelectedIndexChanged);
            // 
            // btnAddChunk
            // 
            this.btnAddChunk.Location = new System.Drawing.Point(12, 217);
            this.btnAddChunk.Name = "btnAddChunk";
            this.btnAddChunk.Size = new System.Drawing.Size(75, 23);
            this.btnAddChunk.TabIndex = 1;
            this.btnAddChunk.Text = "Add Chunk";
            this.btnAddChunk.UseVisualStyleBackColor = true;
            this.btnAddChunk.Click += new System.EventHandler(this.btnAddChunk_Click);
            // 
            // btnRemoveChunk
            // 
            this.btnRemoveChunk.Location = new System.Drawing.Point(93, 217);
            this.btnRemoveChunk.Name = "btnRemoveChunk";
            this.btnRemoveChunk.Size = new System.Drawing.Size(119, 23);
            this.btnRemoveChunk.TabIndex = 2;
            this.btnRemoveChunk.Text = "Remove Chunk";
            this.btnRemoveChunk.UseVisualStyleBackColor = true;
            this.btnRemoveChunk.Click += new System.EventHandler(this.btnRemoveChunk_Click);
            // 
            // btnAddEdge
            // 
            this.btnAddEdge.Location = new System.Drawing.Point(12, 274);
            this.btnAddEdge.Name = "btnAddEdge";
            this.btnAddEdge.Size = new System.Drawing.Size(75, 23);
            this.btnAddEdge.TabIndex = 3;
            this.btnAddEdge.Text = "Add Edge";
            this.btnAddEdge.UseVisualStyleBackColor = true;
            this.btnAddEdge.Click += new System.EventHandler(this.btnAddEdge_Click);
            // 
            // lstEdges
            // 
            this.lstEdges.FormattingEnabled = true;
            this.lstEdges.ItemHeight = 15;
            this.lstEdges.Location = new System.Drawing.Point(12, 303);
            this.lstEdges.Name = "lstEdges";
            this.lstEdges.Size = new System.Drawing.Size(200, 199);
            this.lstEdges.TabIndex = 4;
            // 
            // nudFloor
            // 
            this.nudFloor.Location = new System.Drawing.Point(301, 12);
            this.nudFloor.Maximum = new decimal(new int[] { 255, 0, 0, 0 });
            this.nudFloor.Name = "nudFloor";
            this.nudFloor.Size = new System.Drawing.Size(120, 23);
            this.nudFloor.TabIndex = 5;
            // 
            // nudRoof
            // 
            this.nudRoof.Location = new System.Drawing.Point(301, 41);
            this.nudRoof.Maximum = new decimal(new int[] { 255, 0, 0, 0 });
            this.nudRoof.Name = "nudRoof";
            this.nudRoof.Size = new System.Drawing.Size(120, 23);
            this.nudRoof.TabIndex = 6;
            // 
            // nudLink
            // 
            this.nudLink.Location = new System.Drawing.Point(301, 115);
            this.nudLink.Maximum = new decimal(new int[] { 31, 0, 0, 0 });
            this.nudLink.Name = "nudLink";
            this.nudLink.Size = new System.Drawing.Size(120, 23);
            this.nudLink.TabIndex = 7;
            // 
            // nudTexture
            // 
            this.nudTexture.Location = new System.Drawing.Point(301, 144);
            this.nudTexture.Maximum = new decimal(new int[] { 255, 0, 0, 0 });
            this.nudTexture.Name = "nudTexture";
            this.nudTexture.Size = new System.Drawing.Size(120, 23);
            this.nudTexture.TabIndex = 8;
            // 
            // nudPortal
            // 
            this.nudPortal.Location = new System.Drawing.Point(301, 173);
            this.nudPortal.Maximum = new decimal(new int[] { 255, 0, 0, 0 });
            this.nudPortal.Name = "nudPortal";
            this.nudPortal.Size = new System.Drawing.Size(120, 23);
            this.nudPortal.TabIndex = 9;
            // 
            // btnSaveToJson
            // 
            this.btnSaveToJson.Location = new System.Drawing.Point(301, 217);
            this.btnSaveToJson.Name = "btnSaveToJson";
            this.btnSaveToJson.Size = new System.Drawing.Size(120, 23);
            this.btnSaveToJson.TabIndex = 10;
            this.btnSaveToJson.Text = "Save to JSON";
            this.btnSaveToJson.UseVisualStyleBackColor = true;
            this.btnSaveToJson.Click += new System.EventHandler(this.btnSaveToJson_Click);
            // 
            // btnRemoveEdge
            // 
            this.btnRemoveEdge.Location = new System.Drawing.Point(93, 274);
            this.btnRemoveEdge.Name = "btnRemoveEdge";
            this.btnRemoveEdge.Size = new System.Drawing.Size(119, 23);
            this.btnRemoveEdge.TabIndex = 11;
            this.btnRemoveEdge.Text = "Remove Edge";
            this.btnRemoveEdge.UseVisualStyleBackColor = true;
            this.btnRemoveEdge.Click += new System.EventHandler(this.btnRemoveEdge_Click);
            // 
            // cmbChunks
            // 
            this.cmbChunks.FormattingEnabled = true;
            this.cmbChunks.Location = new System.Drawing.Point(301, 74);
            this.cmbChunks.Name = "cmbChunks";
            this.cmbChunks.Size = new System.Drawing.Size(120, 23);
            this.cmbChunks.TabIndex = 12;
            this.cmbChunks.SelectedIndexChanged += new System.EventHandler(this.cmbChunks_SelectedIndexChanged);
            // 
            // labelFloor
            // 
            this.labelFloor.AutoSize = true;
            this.labelFloor.Location = new System.Drawing.Point(227, 14);
            this.labelFloor.Name = "labelFloor";
            this.labelFloor.Size = new System.Drawing.Size(32, 15);
            this.labelFloor.TabIndex = 13;
            this.labelFloor.Text = "Floor";
            // 
            // labelRoof
            // 
            this.labelRoof.AutoSize = true;
            this.labelRoof.Location = new System.Drawing.Point(227, 43);
            this.labelRoof.Name = "labelRoof";
            this.labelRoof.Size = new System.Drawing.Size(31, 15);
            this.labelRoof.TabIndex = 14;
            this.labelRoof.Text = "Roof";
            // 
            // labelLink
            // 
            this.labelLink.AutoSize = true;
            this.labelLink.Location = new System.Drawing.Point(227, 117);
            this.labelLink.Name = "labelLink";
            this.labelLink.Size = new System.Drawing.Size(28, 15);
            this.labelLink.TabIndex = 15;
            this.labelLink.Text = "Link";
            // 
            // labelTexture
            // 
            this.labelTexture.AutoSize = true;
            this.labelTexture.Location = new System.Drawing.Point(227, 146);
            this.labelTexture.Name = "labelTexture";
            this.labelTexture.Size = new System.Drawing.Size(49, 15);
            this.labelTexture.TabIndex = 16;
            this.labelTexture.Text = "Texture";
            // 
            // labelPortal
            // 
            this.labelPortal.AutoSize = true;
            this.labelPortal.Location = new System.Drawing.Point(227, 175);
            this.labelPortal.Name = "labelPortal";
            this.labelPortal.Size = new System.Drawing.Size(38, 15);
            this.labelPortal.TabIndex = 17;
            this.labelPortal.Text = "Portal";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.labelPortal);
            this.Controls.Add(this.labelTexture);
            this.Controls.Add(this.labelLink);
            this.Controls.Add(this.labelRoof);
            this.Controls.Add(this.labelFloor);
            this.Controls.Add(this.cmbChunks);
            this.Controls.Add(this.btnRemoveEdge);
            this.Controls.Add(this.btnSaveToJson);
            this.Controls.Add(this.nudPortal);
            this.Controls.Add(this.nudTexture);
            this.Controls.Add(this.nudLink);
            this.Controls.Add(this.nudRoof);
            this.Controls.Add(this.nudFloor);
            this.Controls.Add(this.lstEdges);
            this.Controls.Add(this.btnAddEdge);
            this.Controls.Add(this.btnRemoveChunk);
            this.Controls.Add(this.btnAddChunk);
            this.Controls.Add(this.lstChunks);
            this.Name = "Form1";
            this.Text = "Map Editor";
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.nudFloor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudRoof)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudLink)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudTexture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPortal)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        private void CmbChunks_SelectedIndexChanged(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        #endregion

        private System.Windows.Forms.ListBox lstChunks;
        private System.Windows.Forms.Button btnAddChunk;
        private System.Windows.Forms.Button btnRemoveChunk;
        private System.Windows.Forms.Button btnAddEdge;
        private System.Windows.Forms.ListBox lstEdges;
        private System.Windows.Forms.NumericUpDown nudFloor;
        private System.Windows.Forms.NumericUpDown nudRoof;
        private System.Windows.Forms.NumericUpDown nudLink;
        private System.Windows.Forms.NumericUpDown nudTexture;
        private System.Windows.Forms.NumericUpDown nudPortal;
        private System.Windows.Forms.Button btnSaveToJson;
        private System.Windows.Forms.Button btnRemoveEdge;
        private System.Windows.Forms.ComboBox cmbChunks;
        private System.Windows.Forms.Label labelFloor;
        private System.Windows.Forms.Label labelRoof;
        private System.Windows.Forms.Label labelLink;
        private System.Windows.Forms.Label labelTexture;
        private System.Windows.Forms.Label labelPortal;
    }
}
